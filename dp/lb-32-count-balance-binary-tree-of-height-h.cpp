// Height = 0 => No BBT = 0
// Height = 1 => 1
// Hegith = 2 => 3
// Height = 3 => 15
// NOTE: diffrence should be atmost 1 for BBT(Balance BT)
// |Ht(left) - Ht(right)| = 0,1
// C(h) = C(h-1)*C(h-2)[hd=1] + C(h-2)*C(h-1)[hd=1] + C(h-1)*C(h-1) [hd=0]
// C(h) = C(h-1){2*C(h-2) + C(h-1)} => to reduce the multiplications
long long int countBT(int h) {
    long long int mod = 1000000007;
    int dp[h + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
}