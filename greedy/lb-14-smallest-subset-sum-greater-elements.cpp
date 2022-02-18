// Given an array of elements
// find the smallest subset whose sum > sum(remaining elements)
// Method 1: Brute Force exponential
// Generate all subsets, find sum and compare it with remaining sum
// sm = subset sum. sm>sum - sm

// Method 2:
// Sort descending
// choose the elements one by one till become > other sum
#include <algorithm>
#include <iostream>
using namespace std;
int smallest_subset_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    // sort
    sort(arr, arr + n, [](int a, int b) { return a > b; });
    int subset_elements = 0;
    int subset_sum = 0;
    for (int i = 0; i < n; i++) {
        if (subset_sum > sum - subset_sum) break;
        subset_elements++;
        subset_sum += arr[i];
    }
    return subset_elements;
}

int main() {
    int arr[] = {2,2,2};
    int n = sizeof(arr) / sizeof(int);
    cout << smallest_subset_sum(arr, n);
    return 0;
}