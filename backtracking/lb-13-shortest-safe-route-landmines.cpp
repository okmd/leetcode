#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
bool safe(vector<vector<int>>& mat, vector<vector<int>>& visited, int i, int j) {
    return !(visited[i][j] or mat[i][j] == 0 or mat[i][j] == -1);
}
bool valid(int i, int j, int n, int m) {
    return (i < n and j < m and i >= 0 and j >= 0);
}
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
vector<vector<int>>ans;
void helper(vector<vector<int>>& mat, vector<vector<int>>& visited, int i, int j, int& min_dist, int curr_dist) {
    if (j == mat[0].size() - 1) {
        // min_dist = min(min_dist, curr_dist);
        if (min_dist > curr_dist) {
            min_dist = curr_dist;
            ans = visited;
        }
        return;
    }
    if (curr_dist > min_dist) return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y, mat.size(), mat[0].size()) and safe(mat, visited, x, y)) {
            helper(mat, visited, x, y, min_dist, 1 + curr_dist);
        }
    }
    visited[i][j] = 0;

}
void findShortestPath(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    int min_dist = INT_MAX;

    // mark adjacent non rachaable as -1
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (valid(x, y, row, col)) {
                        mat[x][y] = -1;
                    }
                }
            }
        }
    }
    // from 1st col to last col
    vector<vector<int>> visited(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        if (mat[i][0] == 1) {
            for (auto ro : visited) fill(ro.begin(), ro.end(), 0); // reset to 0
            helper(mat, visited, i, 0, min_dist, 0);
            if (min_dist == col - 1) break;
        }
    }
    cout << min_dist << endl;
    for (auto row : ans) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

}
int main() {
    // input matrix with landmines shown with number 0
    vector<vector<int>> mat = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };

    // find shortest path
    findShortestPath(mat);

    return 0;
}
/*
15
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0
*/
// Same can be done using Queue
