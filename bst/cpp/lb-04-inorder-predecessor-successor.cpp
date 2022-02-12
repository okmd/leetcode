
Node *pred(Node *root) {
    // 1 left then
    // extreme right
    root = root->left;
    while (root->right) {
        root = root->right;
    }
    return root;
}
Node *succ(Node *root) {
    // 1 right then
    // extreme left
    root = root->right;
    while (root->left) {
        root = root->left;
    }
    return root;
}
void find_pre_succ(Node *root, Node *pre, Node *suc, int key) {
    if (!root) return;
    if (root->key == key) {
        // if key is found the normally find the predecessor and successor.
        if (root->left) {
            pre = pred(root);
        }
        if (root->right) {
            suc = succ(root);
        }
        return;
    }
    // key exists in the right side of the tree
    if (root->key < key) {
        // maitain a predecessor as right child may not have left child
        // so root will be the predecessor.
        pre = root;
        find_pre_succ(root->right, pre, suc, key);
    } else {
        // key is less i.e in left side of tree
        // maintain the successor as left child may not have right child
        // so root will be the successor of child.
        suc = root;
        find_pre_succ(root->left, pre, suc, key);
    }
}