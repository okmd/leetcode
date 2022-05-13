int get(int i, int j, int n, vector<vector<int>> m) {
    if (i < 0 or j < 0 or i >= n or j >= n) return 0;
    if (i == n - 1) return m[i][j];
    return m[i][j] + max(get(i + 1, j, n, m),
                         max(get(i + 1, j - 1, n, m),
                             get(i + 1, j + 1, n, m)));
}
int maximumPath(int N, vector<vector<int>> Matrix) {
    int maximum = 0, curr;
    for (int i = 0; i < N; i++) {
        curr = get(0, i, N, Matrix);
        maximum = max(maximum, curr);
    }
    return maximum;
}
// #####################3
int get(int i, int j, int n, vector<vector<int>> m) {
    if (i < 0 or j < 0 or i >= n or j >= n) return 0;
    return m[i][j];
}
int maximumPath(int N, vector<vector<int>> mat) {
    int maximum = 0;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0)
                dp[i][j] = mat[i][j];
            else {
                dp[i][j] = mat[i][j] + max({get(i - 1, j, N, dp),
                                            get(i - 1, j - 1, N, dp),
                                            get(i - 1, j + 1, N, dp)});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        maximum = max(maximum, dp[N - 1][i]);
    }

    return maximum;
}

// ##########################
int maximumPath(int N, vector<vector<int>> mat) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) dp[0][i] = mat[0][i];

    int maximum = 0, left, right;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            left = 0, right = 0;
            if (j - 1 >= 0) {
                left = dp[i - 1][j - 1];
            }
            if (j + 1 < N) {
                right = dp[i - 1][j + 1];
            }

            dp[i][j] = mat[i][j] + max({dp[i - 1][j], left, right});
        }
    }
    for (int i = 0; i < N; i++) {
        maximum = max(maximum, dp[N - 1][i]);
    }

    return maximum;
}