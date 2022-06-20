class Solution {
public:
    int n, m;
    vector <vector<string>> ans;
    vector <string> temp;
public:
    void dfs(vector<vector<string>>& A, int i) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }
        for (int k = 0; k < m; k++) {
            temp.push_back(A[i][k]);
            dfs(A, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>& A) {
        n = A.size();
        m = A[0].size();
        dfs(A, 0);
        return ans;
    }

};
// start from 1st row:
// for each row start from 1st col to last col
// take current row and call for next row and start from 1st col for next row: to maintain the oder;