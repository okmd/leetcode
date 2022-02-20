// Given array of elements
// maximize( sum(arr[i]*i))
// order of element can be changed

// to maximize the sum multiply large number with large index
// to minimize the sum multiply the smalle number with small index

int Maximize(int arr[], int n) {
    int mod = 1000000007;
    int sum = 0;
    // for minimum sort reverse using greater<int>
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) sum = (sum + (arr[i] % mod * i % mod) % mod) % mod;
    return sum;
}

// Note: Last test case not working on gfg
