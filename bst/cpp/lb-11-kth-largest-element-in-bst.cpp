// Idea is to take in inorder traversal of the tree.
// take the kth element from the last
// Method 1:
void inorder(Node *root, vector<int> &arr){
    if(!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
int kth_largest(Node *root, int k){
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    return arr[n-k];

}
// Method 2: start from right instead of left
// O(K)
int kth_largest(Node *root, int &K){
    if(!root) return -1;
    int right= kth_largest(root->right, K);
    if(right!=-1) return right;
    if(--K==0) return root->data;
    int left = kth_largest(root->left, K);
    if(left!=-1) return left;
}