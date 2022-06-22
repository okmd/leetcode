#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;

pair<int, int> maxSubarraySum0(vector<int>& arr) {
    int mx = 0;
    int curr_sum = 0;
    int mx_ending = -1;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];
        if (mp.count(curr_sum) != 0) {
            if (mx < i - mp[curr_sum]) {
                mx = i - mp[curr_sum];
                mx_ending = i;
            }
        }
        else mp[curr_sum] = i;
    }
    return { mx, mx_ending };
}

int maximumRectangle(vector<vector<int>> M) {
    int R = M.size();
    int C = M[0].size();
    // NOTE: replace 0 -> -1; then apply kdane it will give max sum having equal 0 and 1;
    // sum will only be 0 when equal 0's and 1's or equal -1's and 1's.
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) M[i][j] = (M[i][j] == 0) ? -1 : 1;
    }
    int row_start = 0, row_end = 0, col_start = 0, col_end = 0;
    int max_len = 0, max_area = 0, curr_area;
    for (int k = 0; k < R; k++) {
        vector<int> row(C, 0);
        for (int i = k; i < R; i++) {
            for (int j = 0; j < C; j++) {
                row[j] += M[i][j];
            }
            auto [mxlen, mx_ending_col] = maxSubarraySum0(row);
            max_area = max_len * (row_end - row_start + 1);
            // compare area not length as len=4(cols), rows = 1 => area 4
            // but cols => 2 and rows => 3 => area 6;
            curr_area = mxlen * (i - k + 1);
            if (max_area <= curr_area) {
                max_len = mxlen;
                row_start = k;
                row_end = i;
                col_start = mx_ending_col - mxlen + 1;
                col_end = mx_ending_col;
            }

        }
    }
    for (int i = row_start; i <= row_end; i++) {
        for (int j = col_start; j <= col_end; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return max_area;
}
int main() {
    vector<vector<int>> M = {
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 1} };
    cout << maximumRectangle(M) << endl;
    return 0;
}
// https://leetcode.com/playground/BjphqzJu