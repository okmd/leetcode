int LISS(Node *root) {
    if (!root) return 0;
    int child = LISS(root->left) + LISS(root->right);
    int gchild = 1;
    if (root->left) {
        gchild += LISS(root->left->left);
        gchild += LISS(root->left->right);
    }
    if (root->right) {
        gchild += LISS(root->right->left);
        gchild += LISS(root->right->right);
    }
    return max(gchild, child);
}

unordered_map<Node *, int> mp;
int LISS(Node *root) {
    if (!root) return 0;
    if (mp.find(root) != mp.end()) return mp[root];
    int child = LISS(root->left) + LISS(root->right);
    int gchild = 1;
    if (root->left) {
        gchild += LISS(root->left->left);
        gchild += LISS(root->left->right);
    }
    if (root->right) {
        gchild += LISS(root->right->left);
        gchild += LISS(root->right->right);
    }
    mp[root] = max(gchild, child);
    return mp[root];
}