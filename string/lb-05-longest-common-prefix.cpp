string longestCommonPrefix(vector<string>& strs) {
    string ans;
    for (int i = 0; i < strs[0].size(); i++) {
        // put 1st string char to match with others
        ans.push_back(strs[0][i]);
        // start from next word ans match ith char
        // if not equal then it can;t be common prefix hence return.
        for (int j = 1; j < strs.size(); j++) {
            // string end is null char -> hence -1
            if (*(ans.end() - 1) != strs[j][i]) {
                ans.pop_back();
                return ans;
            }
        }
    }
    return ans;
}