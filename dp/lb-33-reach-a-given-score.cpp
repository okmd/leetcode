long long int count(long long int n) {
    long long int dp[n + 1], i;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;  // If 0 sum is required number of ways is 1.
    // score i using 3, # ways
    for (int i = 3; i <= n; i++) {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n; i++) {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++) {
        dp[i] += dp[i - 5];
    }
    return dp[n];
}
// unique way to score N using 3,5,10 score
long long int count(long long int n) {
    long long int dp[n + 1][4];
    memset(dp, 0, sizeof(dp));
    int score[3] = {3, 5, 10};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            // no sore to add
            if (i == 0)
                dp[i][j] = 1;
            else if (j == 0)
                dp[i][j] = 0;
            else if (score[j - 1] > i) {
                // exclude current score
                dp[i][j] = dp[i][j - 1];
            } else {
                // include current score coin
                // all those ways to reach till this score by
                // including current score or not
                dp[i][j] = dp[i][j - 1] + dp[i - score[j - 1]][j];
            }
        }
    }
    return dp[n][3];
}