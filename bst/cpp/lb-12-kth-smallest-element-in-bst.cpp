// Idea is to take in inorder traversal of the tree.
// take the kth element from the last
// Method 1:
void inorder(Node *root, vector<int> &arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
int kth_smallest(Node *root, int K) {
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    if(n<K) return -1;
    return arr[K - 1];
}
// Method 2: start from right instead of left
// O(K)
int kth_smallest(Node *root, int &K) {
    if (!root) return -1;
    int left = kth_smallest(root->left, K);
    if (left != -1) return left;
    if (--K == 0) return root->data;
    int right = kth_smallest(root->right, K);
    if (right != -1) return right;
    return -1;
}