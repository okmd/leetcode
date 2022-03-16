class Solution {
   public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // by default, queue is max heap, use greator<dtype> for min heap;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++) pq.push(arr[i]);
        // if only one element hence, can not merge, no cost 0
        if (n == 1) return 0;
        long long ans = 0;
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        return ans;
    }