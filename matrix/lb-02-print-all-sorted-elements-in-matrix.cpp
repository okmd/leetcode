// Given a matrix of sorted rows and columns
// print the sorted array
// Method 1: Young Tableau -> getmin in O(n)
//          O(n^2) *O(n) = O(n^3)

// Method 2: Min-heap : O(n^2) + O(n^2logn^2) = O(N^2LogN).
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> printSorted(vector<vector<int>> &ans) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans.size(); j++) {
            pq.push(ans[i][j]);
        }
    }
    vector<int> arr;
    while (pq.size()) {
        arr.push_back(pq.top());
        pq.pop();
    }
    return arr;
}
int main() {
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    vector<int> ans = printSorted(mat);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}