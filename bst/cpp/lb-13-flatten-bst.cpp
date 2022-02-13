TreeNode *succ = NULL;
TreeNode *flatten1(TreeNode *root) {
    if (!root) return NULL;
    flatten1(root->right);
    flatten1(root->left);
    root->right = succ;
    succ = root;
    root->left = NULL;
    return succ;
}