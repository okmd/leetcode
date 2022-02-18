// Subset is unordered subsequence
#include <iostream>
using namespace std;
// NOTE: this problem is different from the max-product-subarray
int max_product(int arr[], int n) {
    int zeros = 0, negatives = 0, max_negative = INT_MIN;
    int prod = 1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x < 0) {
            negatives++;
            max_negative = max(max_negative, x);
        } else if (x == 0) {
            zeros++;
            continue;
        }
        prod *= x;
    }
    // special case when only one -ve and all zeros then ans is 0; 0, 0, -9, 0
    if (negatives == 1 and zeros + negatives == n) {  // 0, 0, 0, -1, -2, -3
        prod = 0;
    } else if (negatives & 1) {  // -2, -3, 4, 3, 0, -4
        prod = prod / max_negative;
    }
    return prod;
}

int main() {
    int arr[] = {0, 0, 0, 0, -1, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << max_product(arr, n);
    return 0;
}