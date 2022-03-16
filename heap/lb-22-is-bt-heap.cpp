// Given a Binary tree
// find if it is max heap or not
// 1. root >= childs
// 2. should be CBT i.e top->bottom->left->right.
bool helper(struct Node* root, int i, int n) {
    // null is heap
    if (!root) return true;
    // if not CBT
    if (i >= n) return false;
    // root>=childs
    if (root->left and root->data < root->left->data or root->right and root->data < root->right->data) {
        return false;
    }
    // left and right childs are heaps
    return helper(root->left, 2 * i + 1, n) and helper(root->right, 2 * i + 2, n);
}
int all_nodes(struct Node* root) {
    if (!root) return 0;
    return 1 + all_nodes(root->left) + all_nodes(root->right);
}
bool isHeap(struct Node* root) {
    // heap is cbt
    // max heap root if greater than child
    int n = all_nodes(root);
    return helper(root, 0, n);
}