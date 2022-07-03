#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool find(vector<int>& temp, int val) {
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] <= val) {
            temp.erase(temp.begin() + i);
            return true;
        }
    }
    return false;
}
int solve(vector<int>& A) {
    int day = 1;
    int troop = 1;
    int x = 1;
    vector<int> temp = A;
    sort(temp.begin(), temp.end(), [](int a, int b) {
        return a > b;
        });
    while (temp.size()) {
        if (find(temp, troop)) {
            troop = 0;
            x++;
        }
        troop += x;
        day++;
    }
    return day - 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}
/*
3
4 3 1
4
//////
2
9 9
14
////
6
78505027 34547429 92562132 74788475 38129015 54615740
121642331
// https://leetcode.com/playground/WGDLwDdm
// TLE
*/