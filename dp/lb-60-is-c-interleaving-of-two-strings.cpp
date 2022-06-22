bool solve(vector<vector<int>>& dp, string A, string B, string C, int n, int m, int o) {
    if (n < 0 or m < 0) return true;
    if (dp[n][m] != -1) return dp[n][m];

    bool a = (A[n] == C[o]) ? solve(dp, A, B, C, n - 1, m, o - 1) : false;
    bool b = (B[m] == C[o]) ? solve(dp, A, B, C, n, m - 1, o - 1) : false;

    return dp[n][m] = (a or b);

}
bool isInterleave(string A, string B, string C)
{
    int n = A.size();
    int m = B.size();
    int o = C.size();
    if (n + m != o) return false;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(dp, A, B, C, n - 1, m - 1, o - 1);
    return dp[n - 1][m - 1];

}
// Tabulation
bool isInterleave(string A, string B, string C) {
    int n = A.size();
    int m = B.size();
    int o = C.size();
    if (n + m != o) return false;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true; // from blank to blank always possible;
    int k = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int k = i + j - 1;
            if (i == 0) {
                dp[i][j] = (j == 0) ? dp[i][j] : (dp[i][j - 1] and B[j - 1] == C[k]);
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j] and A[i - 1] == C[k];
            }
            else {
                if (A[i - 1] == C[k]) {
                    dp[i][j] = dp[i - 1][j];
                }
                // not use else as if prev is false then it will not check for B as if has already executed;
                // but it may be possible that it can found valid interleaving via B
                // execute B only if A did not find interleaving else B may set true to false; 
                if (!dp[i][j] and B[j - 1] == C[k]) {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[n][m];
}