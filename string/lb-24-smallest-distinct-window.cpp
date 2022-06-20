int findSubString(string str) {
    // idea is to create map of unique char
    // when all unique char comes into the map;
    // remove the 1st repeating char to minimize the windows size; dec count;
    // calc and update the window size if less
    set<char> st;
    for (auto s : str) st.insert(s);
    int n = st.size(); // unique chars; least window size
    int ws = INT_MAX;
    unordered_map<char, int> mp;
    int start = 0;
    for (int i = 0; i < str.size(); i++) {
        char s = str[i];
        if (mp.count(s) == 0) mp[s] = 0;
        mp[s]++;
        if (mp.size() == n) { // as soon as all the unique elemets comes atleast once
            // pop front duplicate to reduce ws
            while (mp[str[start]] > 1) mp[str[start++]]--;
            // current window will contain altest one element(left char).
            ws = min(ws, i - start + 1);
        }
    }
    return ws;
}