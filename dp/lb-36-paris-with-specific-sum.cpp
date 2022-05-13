int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
    // sort so that pairs can be made with least difference
    // and sum can me maximized
    sort(arr, arr + N);
    int sm = 0;
    // each pair is unique
    // hence if pair found the reduce one more step.
    for (int i = N - 1; i > 0; i--) {
        if (arr[i] - arr[i - 1] < K) {
            sm += arr[i] + arr[i - 1];
            i--;
        }
    }
    return sm;
}