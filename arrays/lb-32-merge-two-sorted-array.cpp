// merge without using extra space;
// TLE: ans
void merge(int arr1[], int arr2[], int n, int m) {
    int i = 0;
    int j = 0, k, val, temp;
    while (i < n and j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            val = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = val;
            i++;
            temp = arr2[j];
            k = j;
            while (k < m - 1 and arr2[k + 1] < temp) {
                arr2[k] = arr2[k + 1];
                k++;
            }
            arr2[k] = temp;
        }
    }
}
// Optimization
// if an element more than element in sorted arr2 occured
// that means the last element of arr1 is not part of arr1
// hence move it to arr2
// NO-TLE: as swap require
void merge(int arr1[], int arr2[], int n, int m) {
    int i = 0;
    int j = 0, k = n - 1, temp, val;
    while (i <= k and j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            // swap
            val = arr2[j];
            arr2[j] = arr1[k];
            arr1[k] = val;
            // decrement k and increase j
            //  this is working bcoz the array is sorted.
            j++;
            k--;
        }
    }
    // sort both array in O(n+m) log (n+m)
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}