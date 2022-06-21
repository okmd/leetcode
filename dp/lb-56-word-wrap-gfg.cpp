int solveWordWrap(vector<int>nums, int k) {
    int inf = 100000000;
    int n = nums.size(), t;
    int dp[n][n];
    int cum[n] = { nums[0] };
    for (int i = 1; i < n; i++) {
        cum[i] += cum[i - 1] + nums[i];
    }
    // fill the dp; each cell contains the cost of placing word in each line;
    for (int dis = 0; dis < n; dis++) {
        for (int i = 0, j = dis; j < n; i++, j++) {
            if (dis == 0) {
                t = (k - nums[i]);
            }
            else {
                t = ((i == 0) ? cum[j] : cum[j] - cum[i - 1]) + j - i;
                t = k - t;
            }
            dp[i][j] = (t >= 0) ? t * t : inf;
        }
    }
    vector<int> ans(n, inf);
    // at ans[i]=>cost of placing words from i to end of words(last word);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j >= i; j--) {
            if (dp[i][j] == inf) continue;
            // cost of placing word from i to j and from j+1 to end;
            int sm = (j == n - 1) ? 0 : dp[i][j] + ans[j + 1];
            // last line is not contibuting any extra space;
            ans[i] = min(ans[i], sm);
        }
    }
    return ans[0];
}