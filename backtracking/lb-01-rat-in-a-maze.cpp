// Give an NxN matrix
// find all possible paths in the matrix to reach from source 0,0 to destination.
// A rat can move UDLR
// can only move if cell value is 1.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canMove(vector<vector<int>> &m, int i, int j, int n) {
    if (i < 0 or j < 0 or i >= n or j >= n or m[i][j] <= 0) return false;
    return true;
}
void helper(vector<vector<int>> &m, vector<string> &S, vector<string> &ans, int i, int j, int n) {
    if (i == n - 1 and j == n - 1) {
        // found one path
        string s;
        for (auto x : S) s += x;
        ans.push_back(s);
        return;
    }

    // Mark Visited
    m[i][j] = -1;
    // top
    if (canMove(m, i - 1, j, n)) {
        S.push_back("U");
        helper(m, S, ans, i - 1, j, n);
        S.pop_back();
    }
    if (canMove(m, i + 1, j, n)) {
        S.push_back("D");
        helper(m, S, ans, i + 1, j, n);
        S.pop_back();
    }
    if (canMove(m, i, j - 1, n)) {
        S.push_back("L");
        helper(m, S, ans, i, j - 1, n);
        S.pop_back();
    }
    if (canMove(m, i, j + 1, n)) {
        S.push_back("R");
        helper(m, S, ans, i, j + 1, n);
        S.pop_back();
    }
    // backtrack
    m[i][j] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // m is a matrix of size NxN
    // start location
    int i = 0, j = 0;
    vector<string> ans;
    vector<string> temp;

    if (m[i][j] != 0)
        helper(m, temp, ans, 0, 0, n);

    // if(ans.size()==0)
    //     ans.push_back(to_string(-1));

    return ans;
}

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    int n = 4;
    findPath(m, n);
    return 0;
}