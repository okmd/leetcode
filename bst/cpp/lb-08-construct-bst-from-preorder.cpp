// # https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// # Method 1: O(n^2) for each element start from root and place at its location
Node *method1_helper(Node *root, int val) {
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = method1_helper(root->left, val);
    else if (val > root->data)
        root->right = method1_helper(root->right, val);
    return root;
}
Node *method1(int preorder[]) {
    Node *root = NULL;
    for (auto val : preorder)
        root = method1_helper(root, val);
    return root;
}

// # Method 2: O(nlong) inorder of bst will be sorted so sort preorder and make binary
// # tree which will be unique and BST (nlogn) + O(n)
TreeNode *helper(vector<int> &pre, vector<int> &ino, int i, int j, int k, int l, unordered_map<int, int> &mapping) {
    if (j < i or l < k)
        return NULL;
    TreeNode *root = new TreeNode(pre[i]);
    int in_idx = mapping[pre[i]];
    int elements_left = in_idx - k;
    root->left = helper(pre, ino, i + 1, i + elements_left, k, in_idx - 1, mapping);
    root->right = helper(pre, ino, i + elements_left + 1, j, in_idx + 1, l, mapping);
    return root;
}

TreeNode *method2(vector<int> &pre) {
    int n = pre.size();
    vector<int> ino = pre;
    sort(ino.begin(), ino.end());  //# O(nlogn)

    // #construct tree from inouder and preorder
    unordered_map<int, int> mapping;
    for (int i = 0; i < n; i++) {
        mapping[ino[i]] = i;
    }
    // #pre start - end, ino start - end
    return helper(pre, ino, 0, n - 1, 0, n - 1, mapping);
}

// # Methdo 3: O(n) As the preorder is like ROOT|LEFT|RIGHT so all all elements are in this order only,
// # so create root then left subtree then right subtree
// # instead of starting from root start from current node as the elements will be like ROOT|LEFT|RIGHT
// #points to the next element when a node is created
TreeNode *helper(vector<int> &pre, int &i, int maxx) {
    if (i == pre.size() or pre[i] > maxx) {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[i++]);
    root->left = helper(pre, i, root->val);
    root->right = helper(pre, i, maxx);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &pre) {
    int i = 0;
    return helper(pre, i);
}