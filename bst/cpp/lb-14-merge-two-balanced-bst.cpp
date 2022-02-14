// Method 1: Select the smallest bst take elements from it and insert it to largest one.
// inseration takes O(H) or log(n) for m elements mlogn n>m for better time.

Node *insert(Node *root, int val) {
    if (!root) return new Node(val);
    // if(root->data==val) return root; // do not allow duplicate.
    if (root->data >= val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *merge(Node *root1, Node *root2) {
    if (!root1) return;
    root2 = insert(root2, root1->data);
    merge(root1->left, root2);
    merge(root1->right, root2);
    return root2;
}

// method 2: Select the inorder of both the bst and merge sorted arrays then create new tree.
// O(n) and O(m) for inorder, O(m+m) for merging, O(n+m) for new tree creation
void inorder(Node *root, vector<int> &arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
Node *create(vector<int> &arr, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = create(arr, start, mid - 1);
    root->right = create(arr, mid + 1, end);
    return root;
}
vector<int> merge_array(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr;
    int i = 0, j = 0;
    // till both have same lenth
    while (i < n and j < m) {
        if (arr1[i] < arr2[j]) {
            arr.append(arr1[i++]);
        } else {
            arr.append(arr2[j++]);
        }
    }
    // if either exits
    while (i < n) {
        arr.append(arr1[i++]);
    }
    while (j < n) {
        arr.append(arr2[j++]);
    }
    return arr;
}

Node *merge(Node *root1, Node *root2) {
    vector<int> ino1, ino2;
    inorder(root1, ino1);
    inorder(roo2, ino2);
    // merge two sorted array
    vector<int> arr = merge_array(ino1, ino2);
    // create bst
    return create(arr, 0, arr.size() - 1);
}

// method 3: Inplace using doubly linkedlist O(n+m)
// convert each tree into doubly linked list O(m) and O(m)
// join two sorted linked list O(n+m)
// create list from doubly linked list O(n+m)