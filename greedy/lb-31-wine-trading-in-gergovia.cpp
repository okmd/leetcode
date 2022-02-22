// Given n +ve/-ve values
// +ve means buy from neighbors
// -ve means sell to neighbors
// cost to buy/sell = qty*distance
// minimize total cost of sell/buy
#include <iostream>
#include <vector>
using namespace std;

int minimize_cost(int arr[], int n) {
    vector<pair<int, int>> buy;
    vector<pair<int, int>> sell;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            buy.push_back({arr[i], i});
        else
            sell.push_back({arr[i], i});
    }
    // pick either +ve or -ve and try to nullify each other.
    int i = 0, j = 0;
    int cost = 0;
    while (i < buy.size() and j < sell.size()) {
        int min_value = min(buy[i].first, -sell[j].first);
        cost += min_value * abs(buy[i].second - sell[j].second);
        buy[i].first -= min_value;
        sell[j].first += min_value;
        if (buy[i].first == 0) i++;
        if (sell[j].first == 0) j++;
    }
    return cost;
}

int main() {
    int arr[] = {-1000, -1000, -1000, 1000, 1000, 1000};  //{5, -4, 1, -3, 1};
    int n = sizeof(arr) / sizeof(int);
    cout << minimize_cost(arr, n) << endl;
}