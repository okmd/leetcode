// 1. Simple search O(N) = N-1 for min and N-1 for max

// 2. Tournament method
// Divide into two parts if n=1 then put same element in both parts
// put min of pair in box1 and other(max) in box2
// min will min of mins and max will be max of maxs
// recursively find the same
// O(n) time and O(logn) space
// if n is power of 2 then 3n/2 -2 else > this.
pair<int, int> min_max(int arr[], int l, int r) {
    if (l == r) return {arr[l], arr[r]};  // min, max same
    // only one compare
    if (l + 1 == r) return (arr[l] > arr[r]) ? make_pair(arr[r], arr[l]) : make_pair(arr[l], arr[r]);
    int m = l + (r - l) / 2;
    auto left = min_max(arr, l, m);
    auto right = min_max(arr, m + 1, r);
    // two comparision
    auto min = (left.first < right.first) ? left.first : right.first;
    auto max = (left.second > right.second) ? left.second : right.second;
    return {min, max};
}

// 3. Compare in pairs
// if odd length in set as min and max
// if even the min and max of 1st two ele
// pick in pair and compare with existing min and max
// if n is odd = 3*(n-1)/2
// if n is even = 3n/2 - 2
pair<int, int> min_max(int arr[], int n) {
    pair<int, int> mm;  // min, max
    int i = 0;
    if (n & 1) {
        mm = {arr[0], arr[0]};
        i = 1;
    } else {
        mm = (arr[0] < arr[1]) ? make_pair(arr[0], arr[1]) : make_pair(arr[1], arr[0]);
        i = 2;
    }
    // compare in pairs
    while (i < n - 1) {
        if (arr[i] < arr[i + 1]) {
            mm.first = (arr[i] < mm.first) ? arr[i] : mm.first;
            mm.second = (arr[i + 1] > mm.second) ? arr[i + 1] : mm.second;
        } else {
            mm.first = (arr[i + 1] < mm.first) ? arr[i + 1] : mm.first;
            mm.second = (arr[i] > mm.second) ? arr[i] : mm.second;
        }
        i += 2;
    }
    return mm;
}
