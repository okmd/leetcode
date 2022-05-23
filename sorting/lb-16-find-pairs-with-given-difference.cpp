bool findPair(int arr[], int l, int n) {
    sort(arr, arr + l);
    int i = 0, j = 1;  // start from 1st pair is sorted element will have least diff
    while (i < l and j < l) {
        int diff = arr[j] - arr[i];
        if (i != j and diff == n) return true;  // found diffence
        // if required diff is less then move j++(inc dec) else i++(dec diff)
        (diff > n) ? i++ : j++;
    }
    return false;
}