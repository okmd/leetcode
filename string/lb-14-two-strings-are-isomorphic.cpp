// It should have one-one mapping
// each char in s1 will point to distict char in s2
// a->(a,b) or a <- (a,b) not possible
bool areIsomorphic(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    // mapping of a char from s1->s2
    unordered_map<char, char> mapped;
    // is char of s2 used earlier for any char of s1
    unordered_map<char, bool> used;
    for (int i = 0; i < str1.size(); i++) {
        char ch1 = str1[i];
        char ch2 = str2[i];
        // s1 char is not mapped to any char of s2
        if (!mapped.count(ch1)) {
            // corresponding char is also free to be mapped
            if (!used.count(ch2)) {
                mapped[ch1] = ch2;
                used[ch2] = true;
                // not free erlier used by some other char of s1
                // hence not possible to map ch1->ch2
            } else {
                return false;
            }
            // s1 char is already mapped to some char of s2
            // if corresponding char is same then ok else s1 can;t map to two chars.
        } else if (mapped[ch1] != ch2) {
            return false;
        }
    }
    return true;
}