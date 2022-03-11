#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &q) {
    // pop all elements and insert back
    stack<int> st;
    while (q.size()) {
        st.push(q.front());
        q.pop();
    }
    while (st.size()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    // 1,2,3, ...
    // ..., 3, 2, 1
    queue<int> q;
    for (int i = 0; i < 10; i++) {
        q.push(i + 1);
    }
    reverse(q);
    while (q.size()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}