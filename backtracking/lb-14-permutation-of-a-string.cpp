void permute(string s, int low, int high, set<string>& ans) {
    if (low == high) {
        ans.insert(s);
        return;
    }
    for (int i = low; i <= high; i++) {
        swap(s[low], s[i]);
        permute(s, low + 1, high, ans);
        swap(s[low], s[i]); // backtract to original str
    }

}
vector<string>find_permutation(string S)
{
    set<string> temp;
    permute(S, 0, S.size() - 1, temp);
    vector<string> ans(temp.begin(), temp.end());
    return ans;
}