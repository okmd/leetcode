void helper(vector<vector<int>> &m, int n, int i, int j, vector<string> &ans, string temp) {
    if (i < 0 or j < 0 or i >= n or j >= n or m[i][j] <= 0) return;
    if (i == n - 1 and j == n - 1) {
        ans.push_back(temp);
        return;
    }
    m[i][j] = -1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    // UDLR
    char d[] = {'U', 'D', 'L', 'R'};
    for (int k = 0; k < 4; k++) {
        temp.push_back(d[k]);
        helper(m, n, i + dx[k], j + dy[k], ans, temp);
        temp.pop_back();
    }
    m[i][j] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if (m[0][0] == 0) return ans;
    helper(m, n, 0, 0, ans, "");
    return ans;
}