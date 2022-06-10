int maxGold(int n, int m, vector < vector < int >> M) {
  vector < vector < int >> dp(n + 1, vector < int > (m, 0));
  // for
  for (int j = 0; j < m; j++) { // col
    for (int i = 0; i < n; i++) { // row
      if (i == 0) {
        dp[i][j] = M[i][j] + ((j == 0) ? 0 : max(dp[i][j - 1], dp[i + 1][j - 1]));
      } else if (j == 0) {
        dp[i][j] = M[i][j];
      } else {
        dp[i][j] = M[i][j] + max({
          dp[i - 1][j - 1],
          dp[i][j - 1],
          dp[i + 1][j - 1]
        });
      }
    }
  }
  // max element of last col
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    mx = max(mx, dp[i][m - 1]);
  }
  return mx;
}