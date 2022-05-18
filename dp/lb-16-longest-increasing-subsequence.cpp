int helper(vector<int>& nums, int i, int j, int n) {
    // i = curr, j=prev
    if (i == n) return 0;
    int inc = 0, exc;
    // can include only if previous included element is smaller to make LIS
    if (j == -1 or nums[j] < nums[i]) {
        inc = 1 + helper(nums, i + 1, i, n);
    }
    // if not included then previous will remain same.
    exc = helper(nums, i + 1, j, n);
    return max(inc, exc);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return helper(nums, 0, -1, n);
}