
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// TLE:https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
int min_diff = INT_MAX;

void solve(int pos, vector<int> arr, pair<vector<int>, vector<int>> &ans, vector<int> s1, vector<int> s2) {
    if (pos == arr.size()) {
        int s1_sum = accumulate(s1.begin(), s1.end(), 0);
        int s2_sum = accumulate(s2.begin(), s2.end(), 0);
        if (min_diff > abs(s1_sum - s2_sum)) {
            min_diff = abs(s1_sum - s2_sum);
            ans.first = s1;
            ans.second = s2;
        }
        return;
    }
    if (s1.size() < (arr.size() + 1) / 2) {
        s1.push_back(arr[pos]);
        solve(pos + 1, arr, ans, s1, s2);
        // remove
        s1.pop_back();
    }
    if (s2.size() < (arr.size() + 1) / 2) {
        s2.push_back(arr[pos]);
        solve(pos + 1, arr, ans, s1, s2);
        s2.pop_back();
    }
}

void tug_of_war(vector<int> arr) {
    pair<vector<int>, vector<int>> ans;
    vector<int> s1;
    vector<int> s2;
    solve(0, arr, ans, s1, s2);

    for (auto x : ans.first) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : ans.second) {
        cout << x << " ";
    }
}


int main() {
    vector<int> a = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4, 0};
    tug_of_war(a);
    return 0;
}