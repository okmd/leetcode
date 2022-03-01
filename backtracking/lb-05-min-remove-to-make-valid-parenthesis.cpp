// Given string of character including ()
// remove min parenthesis to make is valid

string minRemoveToMakeValid(string s) {
    stack<int> st;
    vector<char> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
            ans.push_back('(');
        } else if (s[i] == ')') {
            if (st.size() == 0 or s[st.top()] == ')') {
                // do no insert ) inseat mark ans as # because this element is to be removed.
                // due to not valid
                ans.push_back('#');
            } else {
                st.pop();
                ans.push_back(')');
            }

        } else {
            ans.push_back(s[i]);
        }
    }
    // all elements in stack are non valid parenthesis.
    while (st.size()) {
        ans[st.top()] = '#';
        st.pop();
    }
    // create string where not #
    string t;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != '#')
            t.push_back(ans[i]);
    }
    return t;
}