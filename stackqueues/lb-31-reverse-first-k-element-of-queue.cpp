queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> sq;
    int n = q.size();
    n = n - k;
    // push 1st k element in stack
    while (k--) {
        st.push(q.front());
        q.pop();
    }
    // push remaining n-k elements in another queue.
    while (n--) {
        sq.push(q.front());
        q.pop();
    }
    // pushback all elements of stack in original queue.
    while (st.size()) {
        q.push(st.top());
        st.pop();
    }
    // pushback all elements of new Q in original queue.
    while (sq.size()) {
        q.push(sq.front());
        sq.pop();
    }
    // now first k-elements are reversed
    return q;
}