// Given n string of different lengths
// merge the two strings into single string with cost s1+s2
// repeate till it become single string.
// It will give minimum cost only when two minimum string are joined
// e.g 4,3,2,6 => 2+3 => 4,5,6 => 4+5 => 9, 6 => 15 so => 5+ 9+ 15 = 29
// or 6+4 = 10 => 10,2,3 => 13, 3=> 16 => 10+13+16= 39 i.e adding high value each time
// IDEA is to maintain min heap and pop two elements ans insert back sum till only one elements remains
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