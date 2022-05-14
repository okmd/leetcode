int longestPalindromeSubstr(string s) {
    int n = s.size();
    int dp[n][n], cnt = 0;
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {  // move diagonally
            // diagonal with only single element
            if (gap == 0) {
                dp[i][j] = 1;  // true
                // diagonal with 2 elements => if same then pal else not.
            } else if (gap == 1) {
                dp[i][j] = (s[i] == s[j]);
                // more than 2 elements => if same and midlle elements also make palindrom.
            } else {
                dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1]);
            }
            // if current cell is true i.e start from i to j
            // the string is palindromic
            if (dp[i][j]) cnt++;
        }
    }
    return cnt;
}