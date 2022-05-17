int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);
    pq.push({0, 0});  // w, u
    int mst_cost = 0;
    while (pq.size()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        mst_cost += w;

        for (auto x : adj[u]) {  // v, w
            if (!visited[x[0]])
                pq.push({x[1], x[0]});
        }
    }
    return mst_cost;
}