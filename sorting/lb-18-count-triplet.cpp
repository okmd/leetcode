long long countTriplets(long long arr[], int n, long long sm) {
    long long count = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            if (sm > arr[i] + arr[l] + arr[r]) {
                // even including r still sum is less
                // means all the element between l and r will also give less sum
                // as r is maximum ans giving less sum
                // hence total elements = r-l;
                count = count + (r - l);
                l++;
            } else
                r--;
        }
    }
    return count;
}