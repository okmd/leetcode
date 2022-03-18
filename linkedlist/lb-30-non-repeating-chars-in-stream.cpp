string FirstNonRepeating(string s) {
    string ans, temp;
    int frequency[26] = {0};
    int n = s.length();
    bool first;
    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        if (!frequency[index]) {
            // first time occurance
            temp.push_back(s[i]);
        }
        // increase freq as this element has occured
        frequency[index]++;
        first = false;
        // find if fist non-repeating exits for this element or not
        for (int j = 0; j < temp.length(); j++) {
            // occured only 1 time not less or more
            // and this would be first non-repeating char
            if (frequency[temp[j] - 'a'] == 1) {
                first = true;
                ans.push_back(temp[j]);
                break;
            }
        }
        if (!first) ans.push_back('#');
    }
    return ans;
}