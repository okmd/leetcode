#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;
// min{(c, d) - (a, b)};
// c>a and d>b =>
int findMaxValue(vector<vector<int>>& arr) {
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

// DP
// to get maximmum diff a-b a should be as large as possible and b should be as small as possible
// so at each point substract min valid point to get max difference.
int findMaxValue(vector<vector<int>>& mat, int n) {
    int dp[n][n];
    // when there is no valid pairs possible the fill with minium values
    // as they are useful for other valid pair difference to get max difference.
    dp[0][0] = mat[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], mat[i][0]);
        dp[0][i] = min(dp[0][i - 1], mat[0][i]);
    }

    int max_diff = INT_MIN;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            // this is valid diagonal hence subtract current element to min valid previous point
            // update in got greater maximum
            max_diff = max(max_diff, mat[i][j] - dp[i - 1][j - 1]);
            // update the dp value to minimum from current mat element or
            // one stop above and one step left
            // as for i,j all min of (i-1,j-1| i-2, j-2 | i-1, j-2) all are valid pairs
            // as a>c and b>d, hence take minimum from all three
            dp[i][j] = min(mat[i][j], min(dp[i][j - 1], dp[i - 1][j]));
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
    mx_value = findMaxValue(arr, arr.size());
    cout << mx_value << " ";

    return 0;
}