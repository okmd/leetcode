#include <iostream>
#include <string>
#include <vector>
using namespace std;

//
void rearrange(int arr[], int n) {
    int i = 0, j = 0, turn = 1;
    int k = 0;
    while (i < n and j < n) {
        // find -ve
        while (i < n and arr[i] >= 0) {
            i++;
        }
        // find +ve
        while (j < n and arr[j] < 0) {
            j++;
        }

        (turn) ? swap(arr[k++], arr[i++]) : swap(arr[k++], arr[j++]);
        turn = !turn;
    }
}
void rearrange1(int arr[], int n) {
    int i = 0, j = n - 1;
    // arrage array +all positive then all -ve
    while (i < j) {
        while (i < n and arr[i] >= 0) {
            i++;
        }
        while (j >= 0 and arr[j] < 0) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    // if all positive or all -ve
    if (i == 0 or i == n) return;
    int k = 0;
    // create alternate
    // when loop exit i is @ 1st -ve element
    while (k < n and i < n) {
        swap(arr[k], arr[i++]);
        k += 2;  // as -ve, +ve -ve
    }
}
// +ve start and maintain original order
// O(n) space and time
// e.g 9, 4, -2, -1, 5, 0, -5, -3, 2
// 9 -2 4 -1 5 -5 0 -3 2
void rearrange(int arr[], int n) {
    // store +ve and -ve
    vector<int> pos, neg;
    // create +ve and -ve vectors 
    for (int i = 0; i < n; i++) {
        (arr[i] >= 0) ? pos.push_back(arr[i]) : neg.push_back(arr[i]);
    }
    int i = 0, j = 0, k = 0;
    int turn = 1;
    // assign alternate
    while (j < pos.size() and k < neg.size()) {
        arr[i++] = (turn) ? pos[j++] : neg[k++];
        turn = !turn;
    }
    // if still element exits
    while (j < pos.size()) {
        arr[i++] = pos[j++];
    }
    while (k < neg.size()) {
        arr[i++] = neg[k++];
    }
}
int main() {
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);
    // for (int i = 0; i < n; i++) cout << arr[i] << " ";
    // rearrange1(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}