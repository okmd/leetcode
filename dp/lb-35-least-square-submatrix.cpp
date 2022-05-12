int maxSquare(int n, int m, vector<vector<int>> mat) {
    if (!n) return 0;
    int largest = 0;
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i - 1][j - 1] == 1) {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                largest = max(largest, dp[i][j]);
            }
        }
    }
    return largest;
}