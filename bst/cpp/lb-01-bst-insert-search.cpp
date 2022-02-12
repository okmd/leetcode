#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
class BST {
   public:
    Node *root;
    BST() : root(NULL) {}
    Node *insert_helper(Node *root, int val) {
        if (!root) {
            return new Node(val);
        }
        if (root->data == val)
            return root;
        else if (root->data > val) {
            root->left = insert_helper(root->left, val);
        } else {
            root->right = insert_helper(root->right, val);
        }
        return root;
    }
    Node *search_helper(Node *root, int val) {
        if (!root) {
            return NULL;
        }
        if (root->data == val)
            return root;
        else if (root->data > val) {
            return search_helper(root->left, val);
        }
        return search_helper(root->right, val);
    }
    Node *insert(int val) {
        // assign to root as root may not exits.
        root = insert_helper(root, val);
        return root;
    }
    Node *search(int val) {
        return search_helper(root, val);
    }
};

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    BST b = BST();
    for (auto x : arr) {
        b.insert(x);
    }
    for (auto x : arr) {
        cout << x << "=" << b.search(x)->data << ", ";
    }
    cout << b.search(11);
    return 0;
}