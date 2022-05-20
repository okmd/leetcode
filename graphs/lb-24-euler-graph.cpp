// # Walk => any random traversal in graph(V, E can be repeated).
// # Trail=>  A walk in which no edge is repeated(V, can be repeated)
// # Euler circuit=> Trail in which or eulee path which start and end at same vertex
// #   (1). start == end vertex
// #   (2). Every edge is visited exactly ones (all V should have even degree as in and out to reach source again)
// # Euler Graph => has euler circuit
// #   (1). Single component (All edges must be in single comp)
// #   (2). Other compoenets should not have any edge(only single isolated node).
// # Graph with no edge is also a Euler graph.
// # Euler path => is a path visits every edge exaclty once.
// # Semi Eulerian graph
// # Every edge is visited once and start!=end
// # (1). Alteast one vertex should have odd degree
// # (2). All non-zero vertex must be connected
// HOw to check if Euler Graph
// 1. Connectivity check -> if all edges are in one component only
// 1.1 find a node with degree >0  do DFs and mark all node in component
// check if there is any node unvisited and degree>0 if yes then not Euler Graph
// 2. Count odd degree node (bcz more than one component and edges are not in single comp)
// 2.1 cnt = 0 euler graph
// 2.2 cnt = 2 semi euler
// 2.3 cnt >2 not euler
void DFS(vector<int> adj[], vector<bool> &visited, int curr) {
    visited[curr] = true;
    for (auto u : adj[curr]) {
        if (!visited[u]) {
            DFS(adj, visited, u);
        }
    }
}
bool connected(vector<int> adj[]) {
    // all edges lies in single component
    vector<bool> visited(n, false);
    int node = -1;  // start node
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 0) {
            node = i;  // node with >0 degree to start DFS
            // to check all edges lies in this component or not
            break;
        }
    }
    // no node is present with degree>0
    // no edges are present hence can be euler graph
    if (n == -1) return true;
    DFS(adj, visited, node);
    // check if still unvisited node with degree >0 exits
    // if yes then edges are present in more than one compenent
    for (int i = 0; i < n; i++) {
        if (!visited[i] and adj[i].size() > 0) {
            return false;
        }
    }
    // all edges are in one component
    // rest components are single node without edges
    return true;
}
int is_euler(vector<int> adj[], int n) {
    // all edges are not in one compenent
    // hence not euler circuit hence not EG
    // as each edge must be visited exaclty ones in EC.
    if (!all_edges_in_one_comp(adj, n)) return 0;
    // count odd degree node
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() & 1) odd++;
    }
    if (odd > 2) return 0;     // not euler
    return (odd = 0) ? 2 : 1;  // euler and semi euler
}
// NOTE: TESTED on LC or anyother platform