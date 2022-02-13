// Binary tree LCA.
Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 or root->data == n2) return root;
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left and right) return root;

    if (left) return left;
    if (right) return right;
}
// BST LCA
Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    // both values lies in left subtree; can say because it is bst.
    if (root->data > n1 and root->data > n2) {
        return LCA(root->left, n1, n2);
    } else if (root->data < n1 and root->data < n2) {
        // Both values lies in right subtree.
        return LCA(root->right, n1, n2);
    }
    // one lies in left sub tree and other in right subtree
    // hence LCA will always be root;
    // root is LCA when one is decendent of other
    return root;
}