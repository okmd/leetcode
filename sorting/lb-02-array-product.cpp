vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    vector<long long int> pre_sum(n + 1, 0), suf_sum(n + 1, 0);
    pre_sum[0] = 1;
    suf_sum[n] = 1;
    for (int i = 1, j = n - 1; i <= n; i++, j--) {
        pre_sum[i] = nums[i - 1] * pre_sum[i - 1];
        suf_sum[j] = nums[j] * suf_sum[j + 1];
    }
    vector<long long int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(pre_sum[i] * suf_sum[i + 1]);
    }
    return ans;
}