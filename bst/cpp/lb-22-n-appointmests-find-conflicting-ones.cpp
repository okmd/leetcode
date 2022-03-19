// First the idea is to start from second appointment
// then compare all previous conflicting appointments if present.
// two appointments are said to be conflicting(if not sorted) as
// when s1<s2 and s2<e1
// when s1>s2 and s2<e2
// https://www.geeksforgeeks.org/interval-tree/
// Each node represent interval and max value of current subtree
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node {
   public:
    // interval low, high
    // max value in current sumtree rooted at this node.
    pair<int, int> interval;
    int max;
    Node *left, *right;
    Node(pair<int, int> p) {
        interval = p;
        max = (p.first > p.second) ? p.first : p.second;
        left = NULL;
        right = NULL;
    }
};
// bst based on low value of interval
Node *insert(Node *root, pair<int, int> p) {
    if (!root) return new Node(p);
    if (p.first < root->interval.first) {
        root->left = insert(root->left, p);
    } else {
        root->right = insert(root->right, p);
    }
    int maximum = (p.first > p.second) ? p.first : p.second;
    root->max = max(root->max, maximum);
    return root;
}

// if both interval intersects
bool is_overlapping(pair<int, int> n1, pair<int, int> n2) {
    return (n1.first < n2.second and n2.first < n1.second);
}

pair<int, int> find_conflicting_intervals(Node *root, pair<int, int> p) {
    if (!root) return {-1, -1};
    if (is_overlapping(root->interval, p)) {
        return root->interval;
    }
    if (root->left and root->left->max >= p.first)
        return find_conflicting_intervals(root->left, p);
    return find_conflicting_intervals(root->right, p);
}
void show(Node *root) {
    if (!root) return;
    show(root->left);
    cout << "[" << root->interval.first << "-" << root->interval.second << ":" << root->max << "]\n";
    show(root->right);
}
int main() {
    // Let us create interval tree shown in above figure
    vector<pair<int, int>> arr = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    cout << "Following are conflicting intervals\n";
    // create tree
    Node *root = NULL;
    for (auto p : arr) {
        root = insert(root, p);
    }
    // show(root);
    for (auto i : arr) {
        pair<int, int> p = find_conflicting_intervals(root, i);
        cout << "(" << i.first << ", " << i.second << ") With (" << p.first << ", " << p.second << ")\n";
    }
    pair<int, int> p = find_conflicting_intervals(root, {130, 220});
    cout << "(" << p.first << ", " << p.second << ")\n";
    return 0;
}
// Following are conflicting intervals
// (1, 5) With (1, 5)
// (3, 7) With (1, 5)
// (2, 6) With (1, 5)
// (10, 15) With (10, 15)
// (5, 6) With (3, 7)
// (4, 100) With (1, 5)
// (-1, -1)
