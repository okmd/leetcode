// given an array of elements
// re arrange the array such that difference between consecutive elelment is minimum.
// diff(ai=ai+1) .. assume circular array

long long int maxSum(int arr[], int n) {
    // sort the array and re-arrange such that consecutive elements have max diff
    // it can only be possible if in sorted array left then rightmost element comes
    sort(arr, arr + n);
    int i = 1, j = n - 2;
    while (i < j) {
        swap(arr[i], arr[j]);
        i += 2;
        j -= 2;
    }
    // find the diff to maximize
    long long int sum = 0;
    for (int i = 0; i < n - 1; i++) sum += abs(arr[i] - arr[i + 1]);
    // add cicular element
    sum += abs(arr[0] - arr[n - 1]);
    return sum;
}