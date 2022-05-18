
// https://www.youtube.com/watch?v=YHSjvswCXC8&ab_channel=Pepcoding
// count(c1mc2) =
// if (c1 == c2) = count(c1m) + count(mc2) + 1
// else (c1!=c2) = count(c1m) + count(mc2) - count(m)

// How?
// seq(c1mc2) = _seq(m)_ + c1seq(m)_ + _seq(m)c2 + c1seq(m)c2
// seq(c1m) =  _seq(m) + c1seq(m)
// seq(mc2) =  seq(m)_ + c1seq(mc2)
// C(c1mc2) = C(_seq(m)_)[A] + C(c1seq(m)_)[B] + (_seq(m)c2)[C] + C(c1seq(m)c2)[D] = A+B+C+D
// C(c1m) = C(_seq(m))[A] + C(c1seq(m))[B] = A+B
// C(mc2) = C(seq(m)_)[A] + C(seq(m)c2)[C] = A+C
// C(m) = C(seq(m)) = A
// When c1 != c2
//      D = 0 as sequence iteself is not palindromic e.g abbc
//      C(c1mc2) = A+B+C
//      C(c1mc2) = A+B+C-A+A = A+B + A+C - A = C(c1m) + C(mc2) - C(m)
// When c1 == c2
//      D = A+1
//      C(c1mc2) = A+B+C+D = A+B+C+A+1 = A+B + A+C + 1 = C(c1m) + C(mc2) + 1
long long int countPS(string s) {
    long long int mod = 1000000007;
    int n = s.size();
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                dp[i][j] = 1;
            } else if (gap == 1) {
                dp[i][j] = (s[i] == s[j]) ? 3 : 2;
            } else {
                long long int temp = (dp[i][j - 1] + dp[i + 1][j]) % mod;
                dp[i][j] = (s[i] == s[j]) ? (temp + 1) % mod : temp - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][n - 1];
}