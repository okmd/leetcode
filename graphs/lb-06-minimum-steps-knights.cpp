int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n) {
    int i = KnightPos[0] - 1;
    int j = KnightPos[1] - 1;
    int y = TargetPos[0] - 1;
    int z = TargetPos[1] - 1;

    queue<pair<int, int>> q;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    q.push({i, j});
    dp[i][j] = 1;
    int dx[] = {1, 1, 2, -2, -1, -1, 2, -2};
    int dy[] = {2, -2, 1, 1, 2, -2, -1, -1};
    int cnt = 0;
    while (q.size()) {
        int m = q.size();
        for (int d = 0; d < m; d++) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (a == y and b == z) return cnt;
            for (int k = 0; k < 8; k++) {
                i = a + dx[k];
                j = b + dy[k];
                if (i < n and j < n and i >= 0 and j >= 0 and !dp[i][j]) {
                    q.push({i, j});
                    dp[i][j] = 1;
                }
            }
        }
        cnt++;
    }

    return -1;
}