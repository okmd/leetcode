bool ispar(string x) {
    stack<char> st;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(' or x[i] == '{' or x[i] == '[') {
            st.push(x[i]);
        } else {
            // if already the stack is empty then no matching opening brackets.
            if (st.size() == 0) return false;

            if (x[i] == ')' and st.top() == '(') {
                st.pop();
            } else if (x[i] == '}' and st.top() == '{') {
                st.pop();
            } else if (x[i] == ']' and st.top() == '[') {
                st.pop();
            } else {
                // if not matching similar e.g (})
                return false;
            }
        }
    }
    return st.size() == 0;
}