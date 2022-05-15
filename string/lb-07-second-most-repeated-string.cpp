string secFrequent(string arr[], int n) {
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]] = 0;
        }
        mp[arr[i]]++;
    }
    auto ans = max_element(mp.begin(), mp.end(), [](auto x, auto y) {
        return x.second < y.second;
    });
    mp.erase(ans->first);
    ans = max_element(mp.begin(), mp.end(), [](auto x, auto y) {
        return x.second < y.second;
    });
    return ans->first;
}