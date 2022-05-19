// ONLY WORK for DIRECTED EDGES
// Dijkstra and bellman-ford are single source shortest paths
// both do not work for -ve weight cycles
// but BF can tell if -ve weight cycle is present while DKsTA cant;
// They both can work for -ve edge weight but not cycles
// BF cant; find shortest path if it is undirected graph ahd has -ve edge.
// BF - Algo
// Relax edges V-1 times to get shortest path
// relax one more time to check -ve wt cycle
// if current and prev distances are same then no cycle else yes

int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    if (edges.size() == 0) return 0;
    // INT_MAX causes overflow
    vector<int> dist(n, 1000000);
    dist[edges[0][0]] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            // cout<<u<<" "<<dist[u];
            if (dist[u] + w < dist[v]) {
                dist[v] = w + dist[u];
            }
        }
    }
    // one more relax
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] + w < dist[v]) {
            return true;
        }
    }
    // now dist has the shortes path from edges[0][0] i.e source
    // complexity: O(VE)
    return false;
}