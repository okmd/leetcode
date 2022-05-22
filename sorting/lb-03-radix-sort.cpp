#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int digits(int a) {
    int c = 0;
    while (a) {
        c++;  //= a & 1;
        a >>= 1;
    }
    return c;
}
// couting sort is stable sort i.e order remains same

void bucket_sort(vector<int> &arr) {
    int n = arr.size();
    int largest = *max_element(arr.begin(), arr.end());
    int k = digits(largest);
    vector<int> sorted(n, 0);
    for (int i = 0; i < k; i++) {
        int frequency[2] = {0};
        for (int j = 0; j < n; j++) {
            frequency[(bool)(arr[j] & (1 << i))]++; // 100 & 100 = 4 not 1
        }
        frequency[1] += frequency[0];
        for (int j = n - 1; j >= 0; j--) {
            int ith = (bool)(arr[j] & (1 << i));
            frequency[ith]--;
            sorted[frequency[ith]] = arr[j];
        }
        arr = sorted;
    }
}
int main() {
    vector<int> arr = {4, 3, 5, 2, 32};
    int n = arr.size();
    bucket_sort(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}