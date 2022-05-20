int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int inf = 1000000;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<int> visited(n, -1);  // visited at level
    vector<int> distance(n, inf);
    distance[src] = 0;
    visited[src] = 0;
    pq.push({distance[src], src, visited[src]});
    // create adj
    vector<pair<int, int>> adj[n];
    for (auto f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }
    while (pq.size()) {
        auto [w, u, level] = pq.top();
        pq.pop();
        if (u == dst) return w;  // as minimum cost is always picked
        // first time destination is picked then it will have the min cost
        if (level > k) continue;
        for (auto& [v, cost] : adj[u]) {
            // https://leetcode.com/submissions/detail/703208330/
            // Some time small cost(large path) path may not lead to solution while large cost path with less stop can lead to solution(due to k).
            // push only if min cost path is avaible irrespective of visited or not
            // or less stops path
            if (distance[v] > cost + w or visited[v] > level + 1) {
                // include that node if cost is less or have more cost but less stop
                distance[v] = cost + w;
                visited[v] = level + 1;
                pq.push({distance[v], v, level + 1});
            }
        }
    }
    return (distance[dst] == inf) ? -1 : distance[dst];
}