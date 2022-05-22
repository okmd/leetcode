int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    int i = 0, j = 0;
    int c = 1;
    while (i < n and j < m and c < k) {
        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
        c++;
    }
    while (c < k and i < n) {
        c++;
        i++;
    }
    while (c < k and j < m) {
        c++;
        j++;
    }
    if (i == n) return arr2[j];
    if (j == m) return arr1[i];
    return (arr1[i] < arr2[j]) ? arr1[i] : arr2[j];
}