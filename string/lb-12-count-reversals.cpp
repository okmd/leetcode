int countRev(string s) {
    int n = s.length();
    if (n & 1) return -1;
    stack<char> st;
    int closing_in_begining = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{')
            st.push(s[i]);
        else if (st.size() and st.top() == '{')
            st.pop();
        else {
            st.push(s[i]);
            closing_in_begining++;
        }
    }
    n = st.size();
    int opening = 0;
    while (st.size()) {
        opening += (st.top() == '{');
        st.pop();
    }
    // }}}{{{ = {}(1)}{{}(1) = }{ = {}(2) + 2 = 4
    // }}{{ = {}{} = 1+1 = 2
    int ans = 0;
    ans += closing_in_begining / 2;
    ans += opening / 2;
    // if closing_in_begining is odd then opening will also be odd
    // hence will require 2 more operation }{ = {}
    return (closing_in_begining & 1) ? ans + 2 : ans;
}