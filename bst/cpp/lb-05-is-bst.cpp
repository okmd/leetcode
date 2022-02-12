// https://leetcode.com/problems/validate-binary-search-tree
// it will not work when value is INT_MIN/MAX
bool isBst(TreeNode *root, int mn, int mx) {
    if (!root) return true;
    bool curr = mn <= root->val and root->val <= mx;
    return isBst(root->left, mn, root->val - 1) and isBst(root->right, root->val + 1, mx) and curr;
}
// all testcase pass
bool isBst(TreeNode *root, TreeNode *mn = nullptr, TreeNode *mx = nullptr) {
    if (!root) return true;
    if (mn and root->val <= mn->val) return false;
    if (mx and root->val >= mx->val) return false;
    return isBst(root->left, mn, root) and isBst(root->right, root, mx);
}
