// TLE OF LC
int superEggDrop(int k, int n) {
    // @kth floor e/n = e-1/k-1, e/n-k
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {      // floor
        for (int j = 0; j <= k; j++) {  // eggs
            // if there is no egg or no floor
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            // there is only one egg then @ worst case all floors needs to be checked
            else if (j == 1)
                dp[i][j] = i;
            // if there is only one floor then 1 check (for any eggs)
            else if (i == 1)
                dp[i][j] = 1;
            else {
                // drop from each floor
                // take max of steps with either break or not
                // min of all those worst case
                int min_moves = INT_MAX;
                for (int l = 1; l <= i; l++) {
                    // @lth floor => with j eggs and i floors = break(j-1/l-1), not breaked(j/i-l)
                    min_moves = min(min_moves, max(dp[l - 1][j - 1], dp[i - l][j]));
                }
                // add 1 for current drop of egg as an attempt.
                dp[i][j] = min_moves + 1;
            }
        }
    }
    return dp[n][k];
}