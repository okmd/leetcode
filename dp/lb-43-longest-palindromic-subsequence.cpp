int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = n; j >= 0; j--) {
            if (i == 0 or j == n) {
                dp[i][j] = 0;
            } else if (s[i - 1] == s[j]) {
                dp[i][j] = 1 + dp[i - 1][j + 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[n][0];
}