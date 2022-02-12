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

    Node *insert(int val) {
        // assign to root as root may not exits.
        root = insert_helper(root, val);
        return root;
    }
    Node *inorder_scccessor(Node *root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    Node *delete_node(Node *node, int val) {
        if (!node) return NULL;
        if (node->data < val) {
            node->right = delete_node(node->right, val);
        } else if (node->data > val) {
            node->left = delete_node(node->left, val);
        } else {
            // found the node
            // if either leaf or has only one child
            if (!node->left)
                return node->right;
            else if (!node->right)
                return node->left;
            Node *succ = inorder_scccessor(node->right);
            // swap value with root and then remove successorr
            node->data = succ->data;
            node->right = delete_node(node->right, succ->data);
        }
        return node;
    }
    void inorder(Node *node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(int);
    BST b = BST();
    for (auto x : arr) {
        b.insert(x);
    }
    b.inorder(b.root);
    b.delete_node(b.root, 4);
    b.inorder(b.root);
    return 0;
}