// idea is to find dead end which is a node where further nodes cant be inseted.
// dead ends will be leaf nodes only
// constraint is given node value will be >0
// at each node maintain a min and max value that a node can take.
// if min and max become equal then it is a dead end
// as node value will lie in between deadend

bool DeadEnd(Node *root, int mn = 1, int mx = INT_MAX) {
    if (!root) return false;
    bool left = DeadEnd(root->left, mn, root->data - 1);
    bool right = DeadEnd(root->right, root->data + 1, mx);
    if (mn == mx) return true;
    return left or right;
}