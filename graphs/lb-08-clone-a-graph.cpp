Node *dfs(Node *curr, unordered_map<int, Node *> &mp) {
    if (mp.find(curr->val) != mp.end()) return mp[curr->val];
    Node *copy = new Node(curr->val);
    mp[curr->val] = copy;
    for (auto i : curr->neighbors) {
        copy->neighbors.push_back(dfs(i, mp));
    }
    return copy;
}
Node *cloneGraph(Node *node) {
    if (!node) return node;
    unordered_map<int, Node *> mp;
    return dfs(node, mp);
}