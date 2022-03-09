// Bruteforce O(n^2) time and O(n) space
// maintain the in and out digree of each node
// if any one has indegress n-1 and out degree then it is celebrity.
int celebrity(vector<vector<int> >& M, int n) {
    int in[n] = {0};
    int out[n] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // i know j i.e out of i and in of j
            if (M[i][j]) {
                in[j]++;
                out[i]++;
            }
        }
    }
    // if any one has indegress n-1 and out degree then it is celebrity.
    for (int i = 0; i < n; i++) {
        if (in[i] == n - 1 and out[i] == 0) return i;
    }
    return -1;
}

// Optimization: O(n) time and O(1) space;
int celebrity(vector<vector<int> >& M, int n) {
    // assumed one person to be celebrity
    // if he knows next person then he cant be celebrity
    // then assume next one to be celebrity
    // at the end one person will be selected as celebrity
    int current_celebrity = 0;
    for (int i = 1; i < n; i++) {
        // if he know next person then can;t be celebrity
        if (M[current_celebrity][i]) {
            current_celebrity = i;
        }
    }
    // now verify if actually it is celebrity or not
    for (int i = 1; i < n; i++) {
        // is there any other person who i know or
        // is there any person who don;t know me.
        // then he won;t be a celebrity
        if (i != current_celebrity and (M[current_celebrity][i] == 1 or M[i][current_celebrity] == 0)) return -1;
    }
    // he is actual celebrity
    return current_celebrity;
}

// same approach can be used in stack
int celebrity(vector<vector<int> >& M, int n) {
    // push every possible celebrity in stack;
    // pop 2 and check if one knows other
    // puhs back who don;t know(assumned)
    // repeat the process and till only one element is found
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        // if a know b then push b as a can;t be celebrity
        // if a doesn't know b then push a as b can't be celebrity as there is someone who don;t know b(celebrity).
        (M[a][b]) ? st.push(b) : st.push(a);
    }
    int current_celebrity = st.top();
    st.pop();
    // now verify if actually it is celebrity or not
    for (int i = 1; i < n; i++) {
        // is there any other person who i know or
        // is there any person who don;t know me.
        // then he won;t be a celebrity
        if (i != current_celebrity and (M[current_celebrity][i] == 1 or M[i][current_celebrity] == 0)) return -1;
    }
    // he is actual celebrity
    return current_celebrity;
}