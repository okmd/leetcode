void update_map(unordered_map<char, int>& mp, int digit, char start, int count) {
    int i = 0;
    int orig = digit;
    while (count--) {
        mp[start + i] = digit;
        digit = digit * 10 + orig;
        i++;
    }
}
string printSequence(string s) {
    string ans;
    unordered_map<char, int> mp;
    update_map(mp, 2, 'A', 3);
    update_map(mp, 3, 'D', 3);
    update_map(mp, 4, 'G', 3);
    update_map(mp, 5, 'J', 3);
    update_map(mp, 6, 'M', 3);
    update_map(mp, 7, 'P', 4);
    update_map(mp, 8, 'T', 3);
    update_map(mp, 9, 'W', 4);
    mp[(char)32] = 0;

    // for(auto x:mp){
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
    for (int i = 0; i < s.size(); i++) {
        int num = mp[s[i]];
        if (num == 0) {
            ans.push_back('0');
        }
        while (num) {
            ans.push_back(num % 10 + '0');
            num = num / 10;
        }
    }
    return ans;
}