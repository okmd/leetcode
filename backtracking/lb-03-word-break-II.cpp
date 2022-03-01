// Given a word of dictionary
// and a solo word
// find all possible sentances from the words of solo words which are present in the dictionary

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void helper(string s, unordered_map<string, bool>& mp, int pos, vector<string>& ans, vector<string>& temp) {
    if (pos == s.length()) {
        string t = "";
        for (int i = 0; i < temp.size(); i++) {
            if (i == temp.size() - 1)
                t += temp[i];
            else
                t += temp[i] + " ";
        }
        ans.push_back(t);
        return;
    }

    // using for loop will generate all the possible words each time from pos to end
    // foreach function call
    for (int i = pos; i < s.length(); i++) {
        string substr = s.substr(pos, i + 1 - pos);
        if (mp.find(substr) != mp.end()) {
            temp.push_back(substr);
            helper(s, mp, i + 1, ans, temp);
            temp.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans, temp;
    // create hashmap of words for better searching O(n) space
    unordered_map<string, bool> mp;
    for (auto str : wordDict) {
        mp[str] = true;
    }
    helper(s, mp, 0, ans, temp);
    return ans;
}

int main() {
    vector<string> wd = {"apple", "pen", "applepen", "pine", "pineapple"};
    string s = "pineapplepenapple";
    vector<string> ans = wordBreak(s, wd);
    for (auto x : ans) {
        cout << x << ", ";
    }
    return 0;
}
