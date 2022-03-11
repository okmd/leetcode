#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Bruteforce O(n**2): using two loops
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    bool found;
    // n-k
    for (int i = 0; i <= N - K; i++) {
        found = false;
        for (int j = i; j < i + K; j++) {
            if (A[j] < 0) {
                ans.push_back(A[j]);
                found = true;
                break;
            }
        }
        if (!found) ans.push_back(0);
    }
    return ans;
}
// Optimization
vector<long long> printFirstNegativeInteger1(long long int A[], long long int N, long long int K) {
    deque<int> dq;
    vector<long long> ans;
    int window = 0;
    // push all -ve elements of first window of size k.
    while (window < K) {
        if (A[window] < 0) dq.push_back(window);
        window++;
    }
    // from k to n-1, each increment will be another window
    while (window < N) {
        // if element exits then front will be the first -ve.
        // else no negative in window of size k.
        if (!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
        // now remove all elements of dq max K elements if exits.
        while (!dq.empty() and (dq.front() < window - K + 1)) {
            dq.pop_front();
        }
        // as this starting of new window
        // if -ve then this is the first -ve element
        // of this window
        if (A[window] < 0)
            dq.push_back(window);
        // increase the window
        window++;
    }
    // if last window has -ve element it will be front else 0
    if (!dq.empty())
        ans.push_back(A[dq.front()]);
    else
        ans.push_back(0);
    return ans;
}
// Optimization2
vector<long long> printFirstNegativeInteger2(long long int A[], long long int N, long long int K) {
    queue<int> q;
    vector<long long> ans;
    // push -ve in first k-1 elements
    for (int i = 0; i < K - 1; i++) {
        if (A[i] < 0) q.push(A[i]);
    }
    for (int i = K - 1; i < N; i++) {
        if (A[i] < 0) q.push(A[i]);
        // current window completes
        // if -ve elements exits then 1st one is ans
        if (!q.empty()) {
            ans.push_back(q.front());
            // if front element is in Q which is going out of bound(window)
            // then remove, atmost one element will go out of bound because 1 step is slided
            if (q.front() == A[i - K + 1]) {
                q.pop();
            }
            // i is the current pos, i-k+1 index will be out of bound.
        } else {
            // 0 is the ans i.e no negative element
            ans.push_back(0);
        }
    }
    return ans;
}
int main() {
    long long int a[] = {-8, 2, 3, -6, 10};
    long long int n = 5;
    long long int k = 2;
    vector<long long> ans = printFirstNegativeInteger2(a, n, k);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}