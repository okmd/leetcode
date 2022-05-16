void dfs(int curr, vector<int> adj[], vector<int> &visited, stack<int> &st) {
    visited[curr] = 1;
    for (auto n : adj[curr]) {
        if (!visited[n]) {
            dfs(n, adj, visited, st);
        }
    }
    // all of its neighbors are processed
    // post order of current node.
    // ab is node ka koi kaam nhi bacha so store kr lo
    st.push(curr);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> ans;
    while (st.size()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// When all outgoing edges are processed (neighbors) are processed then can be added to stack.
// as all the work has been done in which curr node was dependent.
//