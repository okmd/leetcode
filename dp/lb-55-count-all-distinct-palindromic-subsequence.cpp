
// https://www.youtube.com/watch?v=YHSjvswCXC8&ab_channel=Pepcoding
// count(c1mc2) =
// if (c1 == c2) = c1=c2=c
// if (cmc & m not contains any c) = 2*count(m) + 2
// else if(cmc & m contains only one c) = 2*cpunt(m) +1
// else (contains more than 1 c) = 2*count-count(m);
// else (c1!=c2) = count(c1m) + count(mc2) - count(m)

// How?
int countPalindromicSubsequences(string s) {
    int mod = 1000000007;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prev(n, n), next(n, -1);
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (mp.count(ch) == 0) {
            prev[i] = -1;
        } else {
            prev[i] = mp[ch];
        }
        mp[ch] = i;
    }
    mp.clear();
    for (int i = n - 1; i >= 0; i--) {
        char ch = s[i];
        if (mp.count(ch) == 0) {
            next[i] = -1;
        } else {
            next[i] = mp[ch];
        }
        mp[ch] = i;
    }
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                dp[i][j] = 1;
            } else if (gap == 1) {
                dp[i][j] = 2;
            } else {
                if (s[i] == s[j]) {
                    int next_index = next[i];
                    int prev_index = prev[j];
                    int temp = (2 * dp[i + 1][j - 1]) % mod;
                    if (next_index > prev_index) {
                        dp[i][j] = (temp + 2) % mod;
                    } else if (next_index == prev_index) {
                        dp[i][j] = (temp + 1) % mod;
                    } else {
                        dp[i][j] = temp - dp[next_index + 1][prev_index - 1];
                    }
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1];
                }
            }
            dp[i][j] = dp[i][j] % mod;
        }
    }
    return (dp[0][n - 1] < 0) ? dp[0][n - 1] + mod : dp[0][n - 1];
}