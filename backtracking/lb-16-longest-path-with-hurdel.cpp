#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool valid(vector<vector<int>>& mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();
    return (i < n and j < m and i >= 0 and j >= 0 and mat[i][j] == 1);
}
pair<int, int> findLongestPath(vector<vector<int>>& mat, int i, int j, int x, int y) {
    if (i == x and j == y) return { true, 0 }; // found with length 0
    if (!valid(mat, i, j)) return { false, INT_MAX };

    int ans = INT_MIN;
    
    mat[i][j] = -1;
    for (int k = 0; k < 4; k++) {
        int p = i + dx[k], q = j + dy[k];
        auto [found, length] = findLongestPath(mat, p, q, x, y);
        if (found) ans = max(ans, length);
    }
    mat[i][j] = 1; // as 0 or -1 will not be visited again
    if (ans == INT_MIN) return { false, INT_MAX };
    return { true, 1 + ans };
}
int main() {
    // input matrix with hurdles shown with number 0
    vector<vector<int>> mat = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    // find longest path with source (0, 0) and
    // destination (1, 7)
    int i = 0, j = 0;
    int x = 1, y = 7;
    auto [found, length] = findLongestPath(mat, i, j, x, y);
    cout << (found ? to_string(length) : "Not found\n");
    return 0;
}
// https://leetcode.com/playground/39yreovk