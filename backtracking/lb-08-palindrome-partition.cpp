
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// check if string b/w left and right is palindromic or not
bool is_palindrome(string s, int left, int right) {
    while (left <= right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

void solve(int pos, string s, vector<vector<string>> &ans, vector<string> &path) {
    // if partitioned completely then store the ans
    if (pos == s.length()) {
        ans.push_back(path);
        return;
    }
    // try partition at each location b/w chars
    for (int i = pos; i < s.length(); i++) {
        // push to ans and call only if it palindromic
        if (is_palindrome(s, pos, i)) {
            // add substric which is palendromic before current partition point
            path.push_back(s.substr(pos, i - pos + 1));
            // recurse for remaining string
            solve(i + 1, s, ans, path);
            // pop back to find other possible solution.
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    // it will store the current call ans
    vector<string> path;
    // it will store complete answer of each call
    vector<vector<string>> ans;
    // start partitioning from 0
    solve(0, s, ans, path);
    // return the ans vector
    return ans;
}

int main() {
    string s = "aab";
    partition(s);
    return 0;
}