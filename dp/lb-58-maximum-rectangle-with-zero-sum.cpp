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
        { 9, 7, 16, 5 },
        { 1, -6, -7, 3 },
        { 1, 8, 7, 9 },
        { 7, -2, 0, 10 }};
    cout << maximumRectangle(M) << endl;
    return 0;
}
// https://leetcode.com/playground/6CejihDR