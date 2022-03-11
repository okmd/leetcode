// An Anagram is a word or phrase formed by rearranging the letters
// of a different word or phrase, typically using all the original letters exactly once.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BAISC string
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) return false;
    }
    // or
    // return (s==t)? true : false;
    return true;
}

// O(N**2) Bruteforce -> find lavel order traversal of each tree level by level and compare (recursively);
// both the vectors and compare them iteratively for each level
// O(h2**h) or (nlogn) -> traverse both trees simultaneously level by level. sort and compare.
class Node {
   public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isAnangramTree(Node* root1, Node* root2) {
    // both null then true
    if (!root1 and !root2) return true;
    // if either of the root is null i.e not equal hence false
    if (!root1 or !root2) return false;
    // two queues to store the level order
    queue<Node*> q1, q2;

    q1.push(root1);
    q2.push(root2);
    do {
        int n1 = q1.size();
        int n2 = q2.size();
        // at anytime the size of level is not equal then
        if (n1 != n2) return false;
        vector<int> level1, level2;
        // as the size is equal then check wither n1 or n2
        while (n1--) {
            Node *node1, *node2;
            // tree1
            node1 = q1.front();
            q1.pop();
            if (node1->left) q1.push(node1->left);
            if (node1->right) q1.push(node1->right);
            // tree2
            node2 = q2.front();
            q2.pop();
            if (node2->left) q2.push(node2->left);
            if (node2->right) q2.push(node2->right);

            // match the elements, if level equal true else false
            level1.push_back(node1->data);
            level2.push_back(node2->data);
        }
        // two level order are created for each lavel
        // sort and compare
        sort(level1.begin(), level1.end());
        sort(level2.begin(), level2.end());
        if (level1 != level2) return false;

    } while (q1.size());

    return true;
}
