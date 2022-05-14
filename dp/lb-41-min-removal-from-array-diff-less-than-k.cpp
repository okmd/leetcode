// 1, 2, 5, 1000
// K=4 This approach will not work
// anss should be 1 but this will give 2.
int minRemoval(int arr[], int n, int k) {
    int i = 0;
    int j = n - 1;
    int cnt = 0, ord = true;
    sort(arr, arr + n);
    while (i < j) {
        if (arr[j] - arr[i] <= k) return cnt;
        cnt++;
        (ord) ? i++ : j++;
        ord = !ord;
    }
    return cnt;
}

// This will work
int dp[101][101];
int minRemoval(int arr[], int i, int j, int k) {
    if (i >= j) return 0;
    if (arr[j] - arr[i] <= k) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = 1 + min(minRemoval(arr, i + 1, j, k), minRemoval(arr, i, j - 1, k));
}

// tabulation
int minRemoval(int arr[], int n, int k) {
    ?
}