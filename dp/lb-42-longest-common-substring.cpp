// all Prefix(S1) and prefix(S2) should be compared
// match from end
// if matches then maximum matched suffix is the longest common subsring.

// # In each iretation 0, 1, 2, ... n elements are considered
// i.e no element is present,1, 2, .. all elements are presnet
// the act as prefix of string.
int longestCommonSubstr(string a, string b, int n, int m) {
    int dp[n + 1][m + 1];
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                // matching hence 1 common then find for earlier: AB(C), AB(C)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // not matching hence cant create substring : AB(C), AB(D)
                // prefix end, suffix end
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}