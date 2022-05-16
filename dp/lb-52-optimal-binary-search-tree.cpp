// https://www.youtube.com/watch?v=HnslzEs8dbY&ab_channel=Pepcoding
// Given sorted nodes of BST
// and their search frequency
// find the minimum BST which has minimum seach cost.
// FIND MIN COST

int optimalBST(vector<int> arr, vector<int> freq) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> cum_freq(n, 0);
    cum_freq[0] = freq[0];
    for (int i = 1; i < n; i++) {
        cum_freq[i] = cum_freq[i - 1] + freq[i];
    }
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                dp[i][j] = freq[i];
            // } else if (gap == 1) {
            //     dp[i][j] = min(freq[i] + 2 * freq[j], 2 * freq[i] + freq[j]);
            } else {
                int min_cost = INT_MAX;
                int height_inc_cost = cum_freq[j] - ((i == 0) ? 0 : cum_freq[i - 1]);
                for (int k = i; k <= j; k++) {
                    int left = (k == i) ? 0 : dp[i][k - 1];   // extreme left overflow
                    int right = (k == j) ? 0 : dp[k + 1][j];  // extreme right overflow
                    min_cost = min(min_cost, height_inc_cost + left + right);
                }
                dp[i][j] = min_cost;
            }
        }
    }
    return dp[0][n - 1];
}