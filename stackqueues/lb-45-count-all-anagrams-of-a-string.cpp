vector<int> findAnagrams(string s, string p) {
    // p frequencey will remain same
    // s fre/window will change
    // @ anytime if both freq array matches then it is the correct solution(anagram).
    vector<int> ans, hash(26, 0), pHash(26, 0);
    int window = p.size();
    int n = s.size();
    if (n < window) return ans;
    int left = 0, right = 0;
    // make first window
    while (right < window) {
        pHash[p[right] - 'a']++;
        hash[s[right] - 'a']++;
        right++;
    }
    // slide the window till end
    while (right <= n) {
        // if both have same freq of same chars then this is the valid
        // anagram, push starting index of anagram
        if (hash == pHash) ans.push_back(left);
        if (right < n) hash[s[right] - 'a']++;
        hash[s[left] - 'a']--;
        left++;
        right++;
    }
    return ans;
}