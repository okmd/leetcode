// N nodes need n-1 edges to be connecteds to make single component.
// N nodes need n-1 - c-1 edges to make c component
// eg N=5, C=2 then 3 edges will make 2 componenet
// Redudant edges having c components
// = total edges - (n-1 - (c-1))
// redundant edges >= c-1 then ans = c-1
// edges < n-1 then ans is -1
// red edges < c-1 => -1

void dfs(vector<vector<int>> &adj, vector<int> &visited, int i) {
    visited[i] = true;
    for (auto p : adj[i]) {
        if (!visited[p]) {
            dfs(adj, visited, p);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections) {
    int m = connections.size();
    if (n > m + 1) return -1;
    // create adj
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    // find connected component.
    vector<int> visited(n, 0);
    int component = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component++;
            dfs(adj, visited, i);
        }
    }
    int redEdges = m - (n - 1 - (component - 1));
    return (redEdges >= (component - 1)) ? component - 1 : -1;
    // k-1 more edges are required to make them connected.
    // can k-1 edges can be removed from other componenets with disconnecting them.
}