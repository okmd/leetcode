#include<iostream>
#include<vector>
using namespace std;


int helper(int x, int y, int index, int n, vector<int>& dx, vector<int>& dy, vector<vector<int>>& dp) {
    if (index == n * n) return 1;//found ans
    for (int i = 0; i < dx.size(); i++) {
        int j = x + dx[i];
        int k = y + dy[i];
        if (j >= 0 and k >= 0 and j < n and k < n and dp[j][k] == -1) {
            dp[j][k] = index;
            if (helper(j, k, index + 1, n, dx, dy, dp)) return 1;
            dp[j][k] = -1;
        }
    }
    return 0;

}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> dx = { 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int i = 0, j = 0;
    dp[i][j] = 0; // visited source of knight
    if (!helper(i, j, 1, n, dx, dy, dp)) cout << "No Solution\n";
    else for (auto row : dp) {
        for (auto x : row) {
            cout << x << "\t";
        }
        cout << endl;
    }
    return 0;
}

// O(8N^2)