// Given array of n elements.
// elements are +ve and negative
// make all elements +ve
// if some elements are remaining to negate then negate minimum element.
#include <algorithm>
#include <iostream>
using namespace std;

long long int maximizeSum(long long int arr[], int n, int k) {
    sort(arr, arr + n);
    long long int min_element = INT_MAX;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 and k > 0) {
            arr[i] = -arr[i];
            k--;
        }
        sum += arr[i];
        min_element = min(min_element, arr[i]);
    }
    // find min and change this sign if odd times k else it won;t matter if
    // k is even i.e changing k time sign will not change anything.
    // as the element is already included hence, remove 2 time and k>0.
    if (k & 1) sum -= 2 * min_element;
    return sum;

    // after changing k time if there is any -ve number. i.e no dont need to further modify the sum
    // if k>0 i.e all the elements are already mode +ve and
    // if k is even changing sign even time dont change anythin so do nothing
    // if k is odd then as min_element is already included-> then change sign of min element so that
    // sum is max so remove 2times the min element.
    // min element sign is -ve i.e remove this and already included min_element.
}

int main() {
    long long int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    cout << maximizeSum(arr, n, k);  // 5 | 1,2,3,4,5 | 13 ans
    return 0;
}