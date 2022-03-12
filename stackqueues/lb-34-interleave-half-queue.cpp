#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> interleave(vector<int> &arr) {
    // idea -> 1.push on stack 1st half of queue.
    // 2. enqueue back the stack element.
    // 3. dequene and enqueue half
    // 4. push half in stack
    // 5. now interleave
    // Create a queue
    int n = arr.size();
    int i = 0;
    queue<int> q;
    stack<int> st;
    vector<int> ans;
    // create a Q
    while (i < n) q.push(arr[i++]);
    // 1. create stack from half
    i = 0;
    while (i++ < n / 2) {
        st.push(q.front());
        q.pop();
    }
    // 2. enque back
    while (st.size()) {
        q.push(st.top());
        st.pop();
    }
    // 3. compensation
    i = 0;
    while (i++ < n / 2) {
        q.push(q.front());
        q.pop();
    }
    //
    i = 0;
    while (i++ < n / 2) {
        st.push(q.front());
        q.pop();
    }
    // inderleave
    while (st.size()) {
        ans.push_back(st.top());
        ans.push_back(q.front());
        st.pop();
        q.pop();
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> ans = interleave(arr);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}