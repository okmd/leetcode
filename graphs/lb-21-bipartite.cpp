// Divide vertices into two mutually exclusive and exhaustive set
// non-cyclic graph is always bipartite. [BFS]
// if cycle exits then it must be of even length.
// if odd length cycle exits then guranteed to be not bipartite.

bool helper(vector<int> adj[], vector<int> &visited, int src) {
    queue<pair<int, int>> q;
    q.push({src, 0});  // node and level
    while (q.size()) {
        int curr = q.front().first;
        int level = q.front().second;
        q.pop();
        if (visited[curr] != -1) {
            if (visited[curr] != level) return false;
        } else {
            visited[curr] = level;
        }
        for (auto u : adj[curr]) {
            if (visited[u] == -1) {
                q.push({u, level + 1});
            }
        }
    }
    return true;
}
// if graph is having more than one componenets
bool isBipartite(int V, vector<int> adj[]) {
    vector<int> visited(V, -1);
    for (int i = 0; i < V; i++) {
        if (visited[i] == -1) {
            if (!helper(adj, visited, i)) return false;
        }
    }
    return true;
}

// EXTRA for single component
bool isBipartite(int V, vector<int> adj[]) {
    vector<int> visited(V, -1);
    queue<pair<int, int>> q;
    q.push({0, 0});  // node and level
    while (q.size()) {
        int curr = q.front().first;
        int level = q.front().second;
        q.pop();
        // curr is visited earlier
        if (visited[curr] != -1) {
            // earlier visited in some other level
            // as it should be at same level from source i.e
            // even length cycle
            // if level is not same means odd length cycle
            if (visited[curr] != level) return false;
            // alternate level are place diffrent set of partition
            // e.g even level in set1, odd level in set2
        } else {
            visited[curr] = level;
        }
        for (auto u : adj[curr]) {
            // push un-visited nodes
            if (visited[u] == -1) {
                q.push({u, level + 1});
            }
        }
    }
    return true;
}