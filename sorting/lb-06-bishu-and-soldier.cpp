
// Sample code to perform I/O:

#include <algorithm>
#include <iostream>

using namespace std;
void find(int arr[], int n, int m) {
    int i = 0;
    int sm = 0;
    while (i < n and arr[i] <= m) {
        sm += arr[i];
        i++;
    }
    cout << i << " " << sm << endl;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        find(arr, n, m);
    }
}
