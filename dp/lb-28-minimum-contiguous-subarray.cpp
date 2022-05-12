#include <iostream>
using namespace std;

int min_cont_subarray(int arr[], int n) {
    if (n == 0)
        return 0;
    int min_till_now = arr[0];
    int sum_till_now = arr[0];
    for (int i = 1; i < n; i++) {
        if (sum_till_now > 0) {
            sum_till_now = arr[i];
        } else {
            sum_till_now += arr[i];
        }
        min_till_now = min(min_till_now, sum_till_now);
    }
    return min_till_now;
}
int main() {
    int arr[] = {1, 3, 4, 1, 5, 1};
    cout << min_cont_subarray(arr, 6);
    return 0;
}