// Method 1: O(nlogn) time and O(n) space;
// idea is to first sort the preorder to get inorder of bst O(nlongn)
// when you get bst then create bst using pre and inorder traversal O(n) using https://github.com/okmd/leetcode/blob/main/bst/lb-08-construct-bst-from-preorder.py
// now find the post order traversal of bst O(n)
// so overall time complexity is O(nlogn)
Node* post_order(int pre[], int size) {
    
}

// Method 2: O(n) time and space;
// https://github.com/okmd/leetcode/blob/main/bst/lb-08-construct-bst-from-preorder.py
// dicectly create a bst in o(n) time and then find the postorder traversal of tree.
Node* create_tree(int arr[], int& i, int size, int maxx = INT_MAX) {
    if (i >= size) return NULL;
    if (arr[i] > maxx) return NULL;
    Node* root = new Node(arr[i++]);
    root->left = create_tree(arr, i, size, root->data);
    root->right = create_tree(arr, i, size, maxx);
    return root;
}
Node* post_order(int pre[], int size) {
    int i = 0;
    return create_tree(pre, i, size);
}