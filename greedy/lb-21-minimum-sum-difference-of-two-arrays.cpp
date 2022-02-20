// given two arrays of same size.
// an element of arr1 can be paired with an element of arr2
// sum( abs(arr1i - arr2i) )= should me minimum
// a value should be miminum if you add the least values
// to get least value find min value of arr1 and arr2 this will give least min difference.
// eg. arr1 =  1 < 100 < 200
// eg. arr2 = 50 < 200 < 700
//  diff(1-50) is less than anyother combinations

#include <algorithm>
#include <iostream>
using namespace std;
int min_sum_diff(int arr1[], int arr2[], int n) {
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    int sum = 0;
    for (int i = 0; i < n; i++) sum += abs(arr2[i] - arr1[i]);
    return sum;
}
int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 3, 1};
    cout << min_sum_diff(arr1, arr2, sizeof(arr1) / sizeof(int));
    return 0;
}
