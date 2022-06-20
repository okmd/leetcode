#include<iostream>
#include<vector>
#include<tuple>
#include<stack>
using namespace std;

int dx[8] = { 1, -1, 0, 0, -1,1,1,-1 };
int dy[8] = { 0, 0, -1, 1,-1,1,-1,1 };
bool valid(int i, int j, int n, int m) {
    return (i < n and j < m and i >= 0 and j >= 0);
}
bool solve(vector<vector<char> >& mat, int x, int y, int k, int dir, int n, int m, string target, vector<vector<int>>& ans) {
    // if (mat[x][y] == '#') return true;
    if (k == target.size() - 1) return mat[x][y] == target[k];

    char ch = mat[x][y];
    mat[x][y] = '#';
    if (ch == target[k]) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (valid(nx, ny, n, m) and solve(mat, nx, ny, k + 1, dir, n, m, target, ans)) {
            mat[x][y] = ch; // clear as char may find visited;
            return true;
        }
    }
    mat[x][y] = ch;
    return false;
}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word) {
    int row = grid.size();
    int col = grid[0].size();
    vector<pair<int, int>> start;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == word[0]) {
                start.push_back(make_pair(i, j));
            }
        }
    }
    // now pick each starting point and find if target exits or not
    vector<vector<int>> ans;
    for (auto s : start) {
        int x = s.first;
        int y = s.second;
        for (int i = 0; i < 8; i++) {
            if (solve(grid, x, y, 0, i, row, col, word, ans))
                ans.push_back({ x,y });
        }
    }
    return ans;
}
int main() {
    vector<vector<char> > mat = {
    {'c','a','t'},
    {'a','t','c'},
    {'c','t','a'} };
    string tar = "cat";
    vector<vector<int>> ans = searchWord(mat, tar);
    for (auto c : ans) {
        cout << c[0] << " " << c[1] << endl;
    }
    return 0;
}

// GFG 
bool isOutOfBounds(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word) {
    vector<vector<int>> ans;
    int n = grid.size(), m = grid[0].size();
    int x[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
    int y[] = { 0, 0, 1, -1, -1, -1, 1, 1 };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == word[0]){ // starting char match the procede further.
                bool flag = false; // to check current starting char form the valid target word or not
                for (int d = 0; d < 8 && !flag; d++){ // move to all 8 direction till anyone direction find the complete word;
                    int k = 1, dx = i, dy = j; // start from 2nd char of target word to end of word
                    for (k; k < word.length(); k++) { 
                        dx += x[d], dy += y[d]; // move to direction d only
                        if (!(isOutOfBounds(dx, dy, n, m) && grid[dx][dy] == word[k])) // stop if goes out of bound or any in between char mismatch;
                            break;
                    }
                    // if successfully reached the end of target word then starting point was correct hence add to ans.
                    if (k == word.length())
                        ans.push_back({ i, j }), flag = true; // set flag to true so that no furter direction should be visited
                        // as the source already found the word;
                }
            }
    // finally return the ans;
    return ans;
}