#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &st, int val) {
    if (st.size() == 0) {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insert_at_bottom(st, val);
    st.push(top);
}

void reverse(stack<int> &st) {
    if (st.size() == 0) return;
    int temp = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(st, temp);
}

int main() {
    stack<int> st;
    for (int i = 0; i < 10; i++) st.push(i + 1);
    // top to bottom print
    // before reverse |10 |9 |8 |7 |6 |5 |4 |3 |2 |1
    reverse(st);
    while (st.size()) {
        cout << " |" << st.top();
        st.pop();
    }
    // top to bottom print
    // after reverse |1 |2 |3 |4 |5 |6 |7 |8 |9 |10
}

// same can be done using extra stack