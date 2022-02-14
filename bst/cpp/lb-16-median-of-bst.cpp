// https://www.geeksforgeeks.org/find-median-bst-time-o1-space/
// https://practice.geeksforgeeks.org/problems/median-of-bst/1
// Implementation:
// 1- Count the no. of nodes in the given BST
//    using Morris Inorder Traversal.
// 2- Then Perform Morris Inorder traversal one
//    more time by counting nodes and by checking if
//    count is equal to the median point.
//    To consider even no. of nodes an extra pointer
//    pointing to the previous node is used.

int count(Node *root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}

int helper(Node *root, int &k, Node *&prev) {
    // kth node in inorder traversals
    if (!root) return -1;
    int left = helper(root->left, k, prev);
    if (left != -1) return left;
    if (--k == 0) return root->data;
    prev = root;
    int right = helper(root->right, k, prev);
    if (right != -1) return right;
    return -1;
}

float findMedian(struct Node *root) {
    Node *prev;
    int n = count(root);
    int l = (n + 1) / 2;
    if (n & 1) {  // this root using in-order traversal
        return helper(root, l, prev);
    }
    int k = n / 2 + 1;
    int a = helper(root, k, prev);  // n/2th node and +1 node avg.
    return (prev->data + a) / 2.0;
}