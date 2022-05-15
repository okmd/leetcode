// Each place can pick coin from ends only
// maximize the maximum coin for a player
// return the max coins of a player who have max coins
// IDEA: select Optimal when your turn + assume(worst) as opponent will also select optimally
// hence next time you will have less to select
// find maximum by selecting from both ends.
// NOTE: DO BEST + ASSUME WORST
long long maximumAmount(int arr[], int n) {
    int dp[n][n], left, right;
    // window size or dist(gap) or diagonal
    for (int d = 0; d < n; d++) {
        for (int i = 0, j = d; j < n; i++, j++) {
            if (d == 0) {
                dp[i][j] = arr[i];
            } else if (d == 1) {
                dp[i][j] = max(arr[i], arr[j]);
            } else {
                // I took ith => oppenent will select max(i+1 and i+2)th element
                // so i will have to select => min(i+1, t+2)th element
                left = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                // I took jth => oppenent will select max(j-1 and j-2)th element.
                right = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(left, right);
            }
        }
    }
    // dp[i][j] => maximum possible score from i to j
    // maximum possible score from 0 to n-1 position in arr.
    return dp[0][n - 1];
}

// i---------j coins => arr[i] + min(solve(i+1, j-1), solve(i+2, j))
//                   => arr[j] + min(solve(i, j-2), solve(i+1, j-1))
// as me(i) + if opponenet pick i+1 then i will go with i+2 to j
// if oppoenent pick j then i will go with i+1->j-1