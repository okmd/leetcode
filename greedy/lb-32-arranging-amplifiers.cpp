// Given an array of elements
// find the maximum value when doing operations
// prev = 1, curr power previous and curr become previous
// how to arrange the elements such that number become large
// NOTE: 1,2,3= 1^1 = 1
// 2^1= 2
// 3^2 = 9
// OR sort 3, 2, 1 = 3^1 = 3
// 2^3 = 8
// 1^8 = 1
// NOTE: if one comes at the end then no matter what you do ans will remain same as 1^* = 1
// so place one at starting place. and sort decending order me
// NOTE: x^y when y is large is more tha when y is small and x is large.
#include <algorithm>
#include <iostream>
using namespace std;

void max_amplification(int arr[], int n) {
    // sort reverse
    sort(arr, arr + n, [](int a, int b) {
        return a > b;
    });
    // place one at the begining
    int i = n - 1;
    while (i >= 0) {
        if (arr[i] == 1)
            i--;
        else
            break;
    }
    // shift to right i.e rotate right
    int j = n - 1;
    while (j >= 0 and i >= 0) {
        arr[j--] = arr[i--];
    }
    // place 1
    i = 0;
    while (i <= j) {
        arr[i++] = 1;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() {
    int arr[] = {5, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    max_amplification(arr, n);
}