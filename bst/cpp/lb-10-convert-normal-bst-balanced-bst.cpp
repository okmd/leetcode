void find_inorder(Node *root, vector<int> &ino) {
    if (!root) return;
    find_inorder(root->left, ino);
    ino.push_back(root->data);
    find_inorder(root->right, ino);
}
Node *helper(vector<int> &arr, int start, int end) {
    if (start > end) return NULL;
    int mid = start + int((end - start) / 2);
    Node *root = new Node(arr[mid]);
    root->left = helper(arr, start, mid - 1);
    root->right = helper(arr, mid + 1, end);
    return root;
}
Node *convert_balanced_bst(Node *root) {
    // # find the inorder traversal of tree.
    // # divide in the middle of inorder traversals.
    // # now create left, right child form sub tree.
    vector<int> arr;
    find_inorder(root, arr);
    // sorting is not required as it is already a sbst
    // sort(arr.begin(), arr.end());

    return helper(root, 0, arr.size() - 1);
}
