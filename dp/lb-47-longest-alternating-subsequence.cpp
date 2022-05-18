int AlternatingaMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 1;
    int mx = 0;
    vector<vector<int>> dp(n, vector<int>(2, 1));  // prev less, prev more
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) // all subsequences till j@decreasing + 1
                dp[i][0] = max(1 + dp[j][1], dp[i][0]);
            else if (nums[i] < nums[j])  // not valid of same values
                dp[i][1] = max(1 + dp[j][0], dp[i][1]);
                // all subsequences till j@increasing + 1
        }
        mx = max({mx, dp[i][0], dp[i][1]});
    }
    return mx;
}