// SUBARRAY
// leetcode
// bruteforce generate all sub array and find product ans max of product O(N^2)
int maxProduct(vector<int> &nums) {
    int n = nums.size();
    int ans = nums[0];
    int mn = ans;
    int mx = ans;
    for (int i = 1; i < n; i++) {
        // swap as the -ve*min = +ve large
        // +ve*max = -ve min
        if (nums[i] < 0) {
            swap(mn, mx);
        }
        // use current element to start new sub array
        mx = max(nums[i], mx * nums[i]);
        mn = min(nums[i], mn * nums[i]);
        // if you found max product earlier then ignore less product.
        ans = max(ans, mx);
    }
    return ans;
}