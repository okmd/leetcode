// Given three stacks in the form of arrays
// top is from left to right of array 0->n
// find the maximum sum of elements of each stack when when sum become equal
// sum of stack is sum of all elements present at that moment of time.
#include <iostream>
using namespace std;
int max_sum(int arr1[], int arr2[], int arr3[], int l, int m, int n) {
    // fill the stack with running sum i.e can be done by popping all elements then
    // storing back the sum if data structure is stack
    // here it is array so start from right and save cumulative sum
    for (int i = l - 2; i >= 0; i--) arr1[i] += arr1[i + 1];
    for (int i = m - 2; i >= 0; i--) arr2[i] += arr2[i + 1];
    for (int i = n - 2; i >= 0; i--) arr3[i] += arr3[i + 1];
    // keep on poping till we found equal sum
    // if one og of array finises that means sum can't be eqaul
    int i = 0, j = 0, k = 0;
    while (i < l and j < m and k < n) {
        cout << arr1[i] << " " << arr2[j] << " " << arr3[k] << endl;
        if (arr1[i] == arr2[j] and arr2[j] == arr3[k]) return arr1[i];
        // decrease only the highest sum
        // arr1 is highest => 1>2>3 or 1>3>2
        if (arr1[i] > arr2[j] and arr1[i] > arr3[k])
            i++;
        // arr1 is less than from either arr2 or arr3
        // arr2 is more than arr3 => 2>3>1 or 2>1>3
        else if (arr2[j] > arr3[k])
            j++;
        // arr2 is less than arr3
        // 3>2>1 or 3>1>2
        else
            k++;
    }
    return 0;
}

int main() {
    int arr1[] = {3, 2, 1, 1, 1};
    int l = sizeof(arr1) / sizeof(int);
    int arr2[] = {4, 3, 2};
    int m = sizeof(arr2) / sizeof(int);
    int arr3[] = {1, 1, 1, 4, 1};
    int n = sizeof(arr3) / sizeof(int);
    cout << max_sum(arr1, arr2, arr3, l, m, n);
    return 0;
}