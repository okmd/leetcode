int getMinDiff1(int arr[], int n, int k) {
    sort(arr, arr + n);   // sort the heights
    int mx = arr[n - 1];  // max height will be at end
    int mn = arr[0];      // min height @start
    int diff = mx - mn;   // max difference in tower of max ht and min ht.
    for (int i = 1; i < n; i++) {
        mx = max(arr[i - 1] + k, arr[n - 1] - k);  // increase smaller tower and decrease larger tower
        mn = min(arr[i] - k, arr[0] + k);          //
        diff = min(diff, mx - mn);
    }
    return diff;
}

int getMinDiff2(int arr[], int n, int k) {
    sort(arr, arr + n);   // sort the heights
    int mx = arr[n - 1];  // max height will be at end
    int mn = arr[0];      // min height @start
    int diff = mx - mn;   // max difference in tower of max ht and min ht.
    for (int i = 1; i < n; i++) {
        mx = max(arr[i - 1] + k, arr[n - 1] - k);  // increase smaller tower and decrease larger tower
        mn = min(arr[i] - k, arr[0] + k);          //
        if (mn < 0) continue;                      // 4-(-4) will increase the diff but we need less
        diff = min(diff, mx - mn);
    }
    return diff;
}

// a, c, d, b
// a is smallest, b is largest
// 1. to reduce diff increase smaller and decrease larger
// 2. two adjacent element will give less diff as compared to other pair
// to make smaller distance between c,d => as c<d then increase c and decrease d
// if the max element will be after increasing c and already max of array
// min will be d-k and min of arr i.e a+k
// repeat for all element
// at each index i all the elements from i+1 to n-1 index subtracts k and less than index i add k
// e.g 1,2,3,4,5,6, k=3
// at i=1 => max(prev+k, largest-k) = (1+3, 6-3) = 4
// min(curr-k, smallest+k) = (-1, 1+4) = -1
// diff = 4-(-1) = 5
// now current arr is like 4, -1, 0, 1, 2, 3 => max is 4 min is -1
// @i=2 => 4, 5, 0, 1, 2, 3 => max=5, min=0 => diff = 5