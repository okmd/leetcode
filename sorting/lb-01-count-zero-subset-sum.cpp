// x....x then ...x makes the sum = 0
ll findSubarray(vector<ll> arr, int n) {
    unordered_map<ll, int> mp;
    ll sm = 0, count = 0;
    mp[0] = 1;  // sum 0 exits when there is nothing
    for (auto i : arr) {
        sm += i;
        if (mp.count(sm)) {
            count += mp[sm]++;
        } else {
            mp[sm] = 1;
        }
    }
    return count;
}

// if subset sum to 0 then sum x...x will repeat.
// e.g 0,0,5,5,0,0
// sm, freq
// 0 -> 1 inital default sum to check first time 0 sum
// 0 -> 2 earlier sum 0 is present and after including current element sum remains same hence it must be 0
// 0 -> 3 same
// 5 -> 1 => 1st time 5 occured if in furute sum 5 occurs that means from here to that 5 sum is 0 as range sum not changed even after including.
// 10 ->1
// 10 -> 2 => again getting sum 10 hence from here to previous element where sum was 10 make sum 0
// 10 -> 3=> sum from prev and pre prev