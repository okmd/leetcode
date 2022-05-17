vector<int> nextPermutation(int N, vector<int> arr) {
    int peak = -1;
    for (int i = N - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            peak = i - 1;
            break;
        }
    }
    // if sorted in descending order
    if (peak == -1) {
        // sort in accending order
        sort(arr.begin(), arr.end());
        return arr;
    }
    // find value more than peak
    // as less than peak will decrease the permuation but we need greater
    int i = N - 1;
    while (arr[peak] > arr[i]) {
        i--;
    }
    swap(arr[peak], arr[i]);
    // sort from peak+1 to end
    sort(arr.begin() + peak + 1, arr.end());
    return arr;
}