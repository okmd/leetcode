#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maximum_length_pairs(vector<pair<int, int>> arr) {
    int curr = INT_MIN;
    int ans = 0;
    // sort(arr.begin(), arr.end(), comparator);
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    for (auto ele : arr) {
        if (curr < ele.first) {
            curr = ele.second;
            ans++;
        }
    }
    return ans;
}

int main() {
    int n = 5;
    int src[] = {5, 39, 15, 27, 50};
    int des[] = {24, 60, 38, 40, 90};
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back(make_pair(src[i], des[i]));
    }
    cout << maximum_length_pairs(arr);
    return 0;
}