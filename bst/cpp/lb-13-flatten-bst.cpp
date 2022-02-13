TreeNode *succ = NULL;
TreeNode *flatten(TreeNode *root) {
    if (!root) return NULL;
    flatten(root->right);
    flatten(root->left);
    root->right = succ;
    succ = root;
    root->left = NULL;
    return succ;
}