// De-arrangement: Permulations in which no object occupies its own place.
// D(n) = n!/e
// D(n) = (n-1){D(n-1) + D(n-2)}
// D(n) = n!*sum( (-1)^i / i! )

#include <iostream>
using namespace std;
int dearrangement(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (n - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int dearrangement1(int n) {
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i % 2] = (n - 1) * (dp[0] + dp[1]);
    }
    return dp[n % 2];
}
int main() {
    int n = 5;
    cout << dearrangement(n) << " " << dearrangement1(n) << endl;
    n = 10;
    cout << dearrangement(n) << " " << dearrangement1(n) << endl;
    n = 1;
    cout << dearrangement(n) << " " << dearrangement1(n) << endl;
}