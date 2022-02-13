void find_preorder(Node *root, vector<int> &arr) {
    if (!root) return;
    find_preorder(root->left, arr);
    arr.push_back(root->data);
    find_preorder(root->right, arr);
}
void place(Node *root, int &i, vector<int> &pre) {
    if (!root) return;
    place(root->left, i, pre);
    root->data = pre[i++];
    place(root->right, i, pre);
}
// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST(Node *root) {
    vector<int> pre;
    find_preorder(root, pre);
    sort(pre.begin(), pre.end());
    int i = 0;
    place(root, i, pre);
    return root;
}