bool hasCycle(int curr, int par, vector<int> adj[], vector<int> &visited) {
    visited[curr] = 1;
    for (auto i : adj[curr]) {
        if (!visited[i]) {
            if (hasCycle(i, curr, adj, visited)) return true;
        } else if (i != par)
            return true;
    }
    return false;
}
// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, adj, visited)) return true;
        }
    }
    return false;
}