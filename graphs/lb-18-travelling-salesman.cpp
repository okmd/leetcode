// Start from source and come to source
// find the shorted route
// Hamiltonian cycle => set of edges visits every node and come back to source.
// **TSP = min cost hamiltonian cycle
// brute forece = O(n!) = all permutations of node and find cost for each.
// As due to cyclic permutation : cost of ABCA is same as BCAB or CABC.
// hence reduced to O(n-1)!

int helper(vector<vector<int>>& cost, vector<vector<int>>& dp, int visited, int src, int n) {
    // cost of goining back if all the nodes have been visited
    if (visited == ((1 << n) - 1))
        return cost[src][0];

    if (dp[visited][src] != -1) return dp[visited][src];

    int ans = INT_MAX;
    // visit all nodes from src node.
    for (int des = 0; des < n; des++) {
        if ((visited & (1 << des)) == 0) {  // if not visited des
            ans = min(ans, cost[src][des] + helper(cost, dp, (visited | (1 << des)), des, n));
        }
    }
    dp[visited][src] = ans;
    return ans;
}
int total_cost(vector<vector<int>> cost) {
    int n = cost.size();
    if (!n) return 0;
    int visited = 0;  // 000 no node is visited
    int src = 0;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    // starting node 0
    return helper(cost, dp, visited, src, n);
}
