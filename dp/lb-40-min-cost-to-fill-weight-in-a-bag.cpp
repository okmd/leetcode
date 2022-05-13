int minimumCost(int cost[], int N, int W) {
    int dp[N + 1][W + 1];
    // INT_MAX Overflow when cost is added into it
    for (int i = 0; i <= W; i++) dp[0][i] = 1000007;
    for (int i = 0; i <= N; i++) dp[i][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (i > j or cost[i - 1] == -1) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = min(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= W; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[N][W];
}