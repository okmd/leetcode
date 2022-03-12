// Given two integer arrays pushed and popped each with distinct values,
// return true if this could have been the result of a sequence of
// push and pop operations on an initially empty stack, or false otherwise.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    for (int i = 0; i < pushed.size(); i++) {
        st.push(pushed[i]);
        // remove matching elements only
        // stop if stack empty, or j goes out of bound
        while (j < popped.size() and st.size() and st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }
    return st.size() == 0;
}
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {4, 3, 5, 1, 2};
    cout << validateStackSequences(a, b) << endl;
    return 0;
}