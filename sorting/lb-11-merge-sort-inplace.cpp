// n^2
void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    // one time check for already sorted
    if (arr[j] > arr[m]) return;
    while (i <= m and j <= r) {
        if (arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
            int k = j + 1;
            int temp = arr[j];
            while (k <= r and arr[k] < temp) {
                arr[k - 1] = arr[k];
                k++;
            }
            arr[k - 1] = temp;
        }
        i++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

// Merge using gap method
// logn*n
void merge(int arr[], int l, int m, int r) {
    int gap = (r - l + 1);
    while (gap > 1) {
        gap = ceil(gap / 2.0);
        for (int i = l, j = l + gap; j <= r; i++, j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
// Intuition?Why?