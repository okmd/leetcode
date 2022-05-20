// find connected component with size
// nC2 - {c1C2 + ...}

int dfs(vector<int> adj[], int cnt, bool visited[], int i) {
    visited[i] = true;
    cnt++;
    for (auto j : adj[i]) {
        if (!visited[j]) {
            cnt = dfs(adj, cnt, visited, j);
        }
    }
    return cnt;
}
long int journeyToMoon(int n, vector<vector<int>> edges) {
    bool visited[n] = {0};
    vector<int> size_arr;
    vector<int> adj[n];
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cnt = 0;
            cnt = dfs(adj, cnt, visited, i);
            size_arr.push_back(cnt);
        }
    }
    // total ways to pairs
    // nC2 = n*(n-1)/2
    long long int total = n * (n - 1) / 2;
    // subtract components
    for (auto x : size_arr) {
        long long int curr = x * (x - 1) / 2;
        total -= curr;
    }
    // long int total = 0;
    // int sm = 0;
    // for(auto size:size_arr){
    //     total+= size*sm;
    //     sm+=size;
    // }
    return total;
}
