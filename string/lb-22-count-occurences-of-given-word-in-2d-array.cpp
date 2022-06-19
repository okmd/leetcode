#include<iostream>
#include<vector>
#include<tuple>
#include<stack>
using namespace std;

bool valid(int i, int j, int n, int m) {
    return (i < n and j < m and i >= 0 and j >= 0);
}
void solve(vector<vector<char> >& mat, int x, int y, int k, int n, int m, string target, int& ans) {
    if (mat[x][y] == '#') return;
    if (k == target.size()) {
        ans++;
        return;
    }
    char ch = mat[x][y];
    mat[x][y] = '#';
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny, n, m) and mat[nx][ny] == target[k]) {
            solve(mat, nx, ny, k + 1, n, m, target, ans);

        }
    }
    mat[x][y] = ch;
}
int findOccurrence(vector<vector<char> >& mat, string target) {
    int row = mat.size();
    int col = mat[0].size();
    vector<pair<int, int>> start;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == target[0]) {
                start.push_back(make_pair(i, j));
            }
        }
    }
    // now pick each starting point and find if target exits or not
    int ans = 0;
    for (auto s : start) {
        solve(mat, s.first, s.second, 1, row, col, target, ans);
    }
    return ans;
}
int main() {
    vector<vector<char> > mat = {
    {'c','a','t'},
    {'a','t','c'},
    {'c','t','a'} };
    string tar = "cat";
    cout << findOccurrence(mat, tar);
    return 0;
}