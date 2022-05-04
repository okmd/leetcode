// dfs
// bruteforce : maintain visited
//

bool hasCycle(int i, vector<int> &visited, unordered_map<int, bool> &mp, vector<int> adj[]) {
    visited[i] = 1;
    mp[i] = true;
    for (auto a : adj[i]) {
        if (!visited[a]) {
            if (hasCycle(a, visited, mp, adj)) return true;
        } else {
            if (mp[a]) return true;  // current node is visited and present in calling stack.
        }
    }
    mp[i] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    unordered_map<int, bool> mp;
    // if graph if forest
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycle(i, visited, mp, adj)) {
                return true;
            }
        }
    }
    return false;
}
// bfs- kahns algo
// topological sort - directed acyclic graph
// if unable to generate then cyclic
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    // create in degree
    for (int i = 0; i < V; i++) {
        for (auto a : adj[i]) {
            indegree[a]++;
        }
    }
    // pick indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[n]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    // if all nodes are linearly ordered -> topological sort possible
    // then no cycle
    if (cnt == V) return false;
    return true;
}