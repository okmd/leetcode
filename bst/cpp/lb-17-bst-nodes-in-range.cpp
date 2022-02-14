void helper(Node *root, int l, int h, int &ans) {
    if (!root) return;
    helper(root->left, l, h, ans);
    if (root->data >= l and root->data <= h) ans++;
    helper(root->right, l, h, ans);
}
// Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h) {
    int ans;
    helper(root, l, h, ans);
    return ans;
}