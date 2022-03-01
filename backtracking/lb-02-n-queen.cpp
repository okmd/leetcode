// Given NxN matrix your job is to find all the valid configurations in which Queen
// can be place without attacking other queen
#include <iostream>
#include <vector>
using namespace std;

// O(n)
bool canPlace(vector<vector<int>>& mat, int i, int j, int n) {
    // can only place if it is not place in left side
    // left top/bottom diagonal
    // because=> we are filling col by col values
    // so till now no right col is filled hence checking top, right diagonals(up/down) and bottom is useless(5 directions).
    // So check only left, left diagonals(up/down) (3 directions).
    // left
    for (int r = j; r >= 0; r--) {
        if (mat[i][r]) return false;
    }
    // diagonal left down
    for (int r = i, s = j; r < n and s >= 0; r++, s--) {
        if (mat[r][s]) return false;
    }
    // diagnoal left up
    for (int r = i, s = j; r >= 0 and s >= 0; r--, s--) {
        if (mat[r][s]) return false;
    }
    return true;
}
// O(n^2)
void place(vector<vector<int>>& mat, vector<vector<int>>& ans, int j, int n) {
    // ans found
    if (j == n) {
        // if current col is out of the matrix that means last col is filled with last queen
        // and the numbers of 1s filled are the valid position of the location of the Queen.
        // print matrix or find the Queen location in each col -> store its row value.
        vector<int> v, u;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[j][i] == 1) {
                    v.push_back(j + 1);
                    break;
                }
            }
        }
        ans.push_back(v);
        return;
    }
    // for each col start from row=0 to last row
    // find if can be place then place and find ans for next col
    // when come back remove 1 and set 0 as this is no longer part of solution.
    for (int i = 0; i < n; i++) {
        if (canPlace(mat, i, j, n)) {
            mat[i][j] = 1;
            place(mat, ans, j + 1, n);
            mat[i][j] = 0;
        }
    }
}
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    place(mat, ans, 0, n);

    return ans;
}

int main() {
    // place of Queen at each Col as row number.
    vector<vector<int>> mat = nQueen(5);
    for (auto row : mat) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

// This problem can be optimized using the hashing technique
// by storing the filled row, i.e in the left
// by storing the diagonal left(up/down) (2n-1) size.
// So extra O(n) time can be reduced