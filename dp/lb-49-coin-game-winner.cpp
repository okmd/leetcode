// Any player can choose 1, x, y coins
// A start playing
// Whoever play last is the winner.

// IDEA: N=10, x=4,y=5
// No Coins
// i = 0 => A looser => B Winner @ A can;t start
// i = 1 => A winner => B looser @ A start and choose 1 and win
// i = 2 => A looser => B winnner @ A(1), B(1)
// i = 3 => A winner => B looser @ A(1), B(1), A(1), as there is no choice of x,y
// i = 4 => A winner => B looser @ A(4), A starts and take x coins
//                               i-x = 0 and @ 0 B is winner i.e B ends the game
//                               Now its is next turn, after B and A will play and reaches end(i)
//                               hence at i A is winner.

int coin_game(int x, int y, int n) {
    int dp[n + 1];
    dp[0] = 0;  // A looses
    dp[1] = 1;  // A wins
    for (int i = 2; i <= n; i++) {
        // if for any of the previous point i-1, i-x, i-y B was winner
        // then at this point A end the game and become winner.
        dp[i] = (!dp[i - 1] or (i >= x and !dp[i - x]) or (i >= y and !dp[i - y]));
    }
    return dp[n];
}