// given price of stock on each day
// you can buy a stock on ith day i quantity @same price.
// initially you are given k amount of money
// IDEA: to get maximum stocks you need to get the minimum price stock first
// greedy about the price
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int max_stock_buy(int arr[], int n, int k) {
    vector<pair<int, int>> comb;
    for (int i = 0; i < n; i++) {
        comb.push_back(make_pair(arr[i], i + 1));
    }
    // sort based on price
    sort(comb.begin(), comb.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    //
    int mx_stocks = 0;
    for (int i = 0; i < n; i++) {
        int can_buy_shares = min(comb[i].second, k / comb[i].first);  // 3rd index, 100/10 but can only buy 3 shares
        k -= comb[i].first * can_buy_shares;                          // reduce the price which you have used
        mx_stocks += can_buy_shares;                                  // no of shares you bought.
    }
    return mx_stocks;
}
int main() {
    int prices[] = {10, 7, 19};
    int n = 3;
    int k = 45;
    cout << max_stock_buy(prices, n, k);
    return 0;
}