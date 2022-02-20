// Given an array if integers
// find maximum products
// if all zeros then result is 0
// if odd -ve elements = remove max -ve element
// if even -ve elements then it will automatically become +ve.
#include <iostream>
using namespace std;
// SUBSET
int max_product(int arr[], int n) {
    // if only one element then return that element.
    if (n == 1) return arr[0];
    int product = 1, zeros = 0, negatives = 0;
    int max_negative = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            // as including 0 will change product to 0
            zeros++;
            continue;
        }
        if (arr[i] < 0) {
            max_negative = max(max_negative, arr[i]);
            negatives++;
        }
        product *= arr[i];
    }
    // if all zeros or // special case 0,0,0,-1
    if (zeros == n or zeros + negatives == n) return 0;
    if (negatives & 1) return product / max_negative;
    return product;
}

int main() {
    int a[] = {2, 3, -2, 4};
    int n = sizeof(a) / sizeof(int);
    cout << max_product(a, n) << endl;
    return 0;
}