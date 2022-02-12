#include <iostream>
#include <numeric>
#include <vector>
#define ll long long
using namespace std;

vector<vector<int>> keypadmap = {{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8}, {0, 5, 7, 8, 9}, {6, 8, 9}};
ll mobile_keypad(int n) {
    ll dp[n][10] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0)
                dp[i][j] = 1;
            else {
                for (auto k : keypadmap[j]) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    return accumulate(dp[n - 1], dp[n - 1] + (ll)10, (ll)0);
}

int main() {
    // lamda funtion to find sum
    cout << mobile_keypad(1) << endl;
    cout << mobile_keypad(16);
    return 0;
}
