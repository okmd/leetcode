// In a graph from each node every other node must be reachable.
// undirected graph with 1 component is strongly connected.
// or UG strongly connected components = components (each component is strongly connected)
// directed graph => k=1 may or may not be strongly connected.
// single node is always strongly connected.

// Brute Forec => all pair shortest paths bellmanford => if INF then not reachable hence not strongly connected

// Property: reversing or changing the edge direction will not change strongly connected components(SCC)
// this is known as Transpose of graph.
// ## KOSRAJU: DFS->Reverse->DFS
// NOTE: strong1 -> strong2 after reversing the direction strong2 will not be accessable
// becz strong2 has no way to visit any node of strong1
// dfs of SCC will be same after changing the direction.
void DfsFull(vector<int> adj[], vector<bool> &visited, stack<int> &st, int i) {
    visited[i] = true;
    for (auto j : adj[i]) {
        if (!visited[j]) DfsFull(adj, visited, st, j);
    }
    st.push(i);
}
void DfsComponent(vector<int> adj[], vector<bool> &visited, int i) {
    visited[i] = true;
    for (auto j : adj[i]) {
        if (!visited[j]) DfsComponent(adj, visited, j);
    }
}
void reverse(int V, vector<int> adj[], vector<int> rev[]) {
    for (int i = 0; i < V; i++) {
        for (auto j : adj[i]) {
            rev[j].push_back(i);  // vector
        }
    }
}
int kosaraju(int V, vector<int> adj[]) {
    vector<int> rev[V];
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) DfsFull(adj, visited, st, i);
    }
    reverse(V, adj, rev);
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    int component = 0;
    while (st.size()) {
        int curr = st.top();
        st.pop();
        if (!visited[curr]) {
            component++;
            DfsComponent(rev, visited, curr);
        }
    }
    return component;
}