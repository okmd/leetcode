// TLE ON GFGs
int minJumps(int arr[], int n) {
    int max_reachable_index = 0;
    int dp[n];
    fill(dp, dp + n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (max_reachable_index < i) return -1;
        max_reachable_index = max(max_reachable_index, i + arr[i]);
        for (int j = i + 1; j <= min(max_reachable_index, n - 1); j++) {
            dp[j] = min(1 + dp[i], dp[j]);
        }
    }
    return dp[n - 1];
}