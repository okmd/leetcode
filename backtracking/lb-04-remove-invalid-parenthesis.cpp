// Given string of opening and closing parenthesis.
// Task is remove min invalid parenthesis to make it valid.

// Idea is first find the min invalid parenthesis
// then remove min no of elements from original string if valid then include in the ans
// else dont
// to remove duplicate use set.
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int minInvalid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')') {
            if (st.size() == 0 or st.top() == ')') {
                st.push(')');
            } else {
                st.pop();
            }
        }
    }
    return st.size();
}
void helper(string s, vector<string> &ans, int minRemove, unordered_map<string, bool> &st) {
    // if alreay formed the string.
    // every string will come atleast once
    if (st[s]) return;
    // if first time then mark true.
    st[s] = true;

    if (minRemove == 0) {
        // check if it is valid or not
        // if minRemove required is 0 then valid
        if (minInvalid(s) != 0) return;
        // found the actual ans
        // append to ans only if is not already found
        ans.push_back(s);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        string left = s.substr(0, i);
        string right = s.substr(i + 1, s.length() - i);
        helper(left + right, ans, minRemove - 1, st);
        // cout<<left<<"-"<<right<<endl;
    }
}
//  This solution gives TLE
vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    unordered_map<string, bool> st;
    int minVal = minInvalid(s);
    helper(s, ans, minVal, st);
    return ans;
}

int main() {
    string s = "()(((((((()";
    vector<string> ans = removeInvalidParentheses(s);
    for (auto x : ans) {
        cout << x << ",";
    }
    return 0;
}