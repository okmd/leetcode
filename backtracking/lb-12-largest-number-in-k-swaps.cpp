void helper(string& str, string& ans, int n, int k, int index) {
    if (k == 0) return;
    int mx = str[index];
    for (int i = index + 1; i < n; i++) {
        if (mx < str[i]) {
            mx = str[i];
        }
    }
    if (mx != str[index]) k--;
    for (int i = n - 1; i >= index; i--) {
        if (str[i] == mx) {
            swap(str[i], str[index]);
            if (ans < str) ans = str;
            helper(str, ans, n, k, index + 1);
            swap(str[i], str[index]);
        }
    }
}
string findMaximumNum(string str, int k) {
    int n = str.size();
    string ans = str;
    helper(str, ans, n, k, 0);
    return ans;
}