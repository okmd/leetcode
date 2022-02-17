// You are given an array
// replace each element with next greator element from left to right
// Method 1: Brute force O(n^2)
// foreach element find the next greator element from next element
// if found then replace else -1

// Method 2: using Stack of Non increasing elements O(nlogn) i.e decreasing seq.
vector<long long> replace(vector<long long> arr) {
    stack<int> s;
    for (int i = 0; i < arr.size(); i++) {
        if (s.empty() or arr[s.top()] >= arr[i]) {
            s.push(i);  // insert only index
        } else {
            while (!s.empty() and arr[s.top()] <= arr[i]) {
                arr[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
    }
    // if anything left in stack then its next greator element not exits.
    while (!s.empty()) {
        arr[s.top()] = -1;
        s.pop();
    }
    return arr;
}

// method 3: using BST;O(nlogn) avg and O(N^2) worst case
// create a bst from right to left and maintain a successor at each node
// replace array value from successor
// if it is extrement end then successor is null hence -1
Node *succ = NULL;
Node *helper(Node *root, int val) {
    if (!root) return new Node(val);
    if (root->data > val) {
        succ = root;
        root->left = helper(root->left, val);
    } else {
        root->right = helper(root->right, val);
    }
    return root;
}
Node *root create_bst(vector<long long> arr) {
    Node *root = NULL;
    for (int i = arr.size() - 1; i >= 0; i--) {
        root = helper(root, arr[i]);
        arr[i] = succ->data if (succ) else - 1;
    }
    return root;
}
