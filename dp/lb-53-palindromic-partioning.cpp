// Given a string of chars
// make minimal partition so that each and every substring
// of the partitions are palindrome.

// O(N^3)
int palindromicPartition(string str) {
    int n = str.size();
    vector<vector<int>> palindromic(n, vector<int>(n, 0)), dp(n, vector<int>(n, 0));
    // find is palindromic
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                palindromic[i][j] = 1;
            } else if (gap == 1) {
                palindromic[i][j] = str[i] == str[j];
            } else {
                palindromic[i][j] = (str[i] == str[j] and palindromic[i + 1][j - 1]);
            }
        }
    }
    // min cuts
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (palindromic[i][j]) {
                dp[i][j] = 0;
                // } else if (gap == 1) {
                //     dp[i][j] = str[i] != str[j];
            } else {
                int min_part = INT_MAX;
                for (int k = i; k < j; k++) {
                    min_part = min(min_part, 1 + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = min_part;
            }
        }
    }

    return dp[0][n - 1];
}

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//         cout << dp[i][j] << " ";
//     }
//     cout << endl;
// }

// ########## METHOD 2 #############
// O(N^2)

int palindromicPartition(string str) {
    int n = str.size();
    vector<vector<int>> palindromic(n, vector<int>(n, 0));
    // find is palindromic
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                palindromic[i][j] = 1;
            } else if (gap == 1) {
                palindromic[i][j] = str[i] == str[j];
            } else {
                palindromic[i][j] = (str[i] == str[j] and palindromic[i + 1][j - 1]);
            }
        }
    }
    // min cuts
    // using prefix
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
        if (palindromic[0][i]) {
            dp[i] = 0;  // already palindrome
        } else {
            int min_part = INT_MAX;
            for (int j = 1; j <= i; j++) {
                if (palindromic[j][i]) {
                    min_part = min(min_part, dp[j - 1]);
                }
            }
            dp[i] = 1 + min_part;
        }
    }
    return dp[n - 1];
}