#include <iostream>
#include <string>
#include <vector>
using namespace std;
// min{(c, d) - (a, b)};
// c>a and d>b =>
int findMaxValue(vector<vector<int>> &arr) {
    // Brute-force : generate all possible combinations.O(n^4)
    int n = arr.size();
    int m = arr[0].size();
    int max_diff = INT_MIN;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            for (int c = a + 1; c < n; c++) {
                for (int d = b + 1; d < m; d++) {
                    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<";";
                    max_diff = max(max_diff, arr[c][d] - arr[a][b]);
                }
            }
        }
    }
    return max_diff;
}
int main() {
    vector<vector<int>> arr = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};
    int mx_value = findMaxValue(arr);
    cout << mx_value << " ";

    return 0;
}