int find_min(vector<int> &distance, int n, vector<int> &visited) {
    int mn = INT_MAX;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] and mn >= distance[i]) {
            mn = distance[i];
            index = i;
        }
    }
    return index;
}
vector<int> dijkstra(int n, vector<vector<int>> adj[], int S) {
    vector<int> distance(n, INT_MAX);
    vector<int> visited(n, 0);

    distance[S] = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_dist_node = find_min(distance, n, visited);
        visited[min_dist_node] = 1;
        for (auto x : adj[min_dist_node]) {
            int nei = x[0];
            int dist = x[1];
            if (!visited[nei] and distance[min_dist_node] != INT_MAX) {
                distance[nei] = min(distance[nei], distance[min_dist_node] + dist);
            }
        }
    }
    return distance;
}

// QUEUE method

vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int src) {
    // Array of vectors of pairs
    // pair = (destination, cost)
    // min-heap {dist, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(n + 1, INT_MAX);
    distance[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        for (auto pr : adj[curr]) {
            int neigh = pr.first;
            int edge_cost = pr.second;
            if (distance[neigh] > distance[curr] + edge_cost) {
                distance[neigh] = distance[curr] + edge_cost;
                pq.push({distance[neigh], neigh});
            }
        }
    }
    return distance;
}