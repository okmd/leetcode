// Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
// 1. BruteForce: generate all subarray and find max O(n**2*k)
// 2. DLL DEQUEU: This method uses Deque to solve the above problem
// 2. HEAP
// Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
// Output: 3 3 4 5 5 5 6
// using min heap of size k
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> sliding_window_max_deq(vector<int> arr, int k) {
    deque<int> dq;
    vector<int> ans;
    int i = 0;
    int max_till = INT_MIN;
    // insert 1st k-elements
    while (dq.size() < k - 1) {
        max_till = max(max_till, arr[i]);
        dq.push_back(arr[i++]);
    }
    while (i < arr.size()) {
        max_till = max(max_till, arr[i]);
        ans.push_back(max_till);
        dq.push_back(arr[i++]);
        // slide windows
        dq.pop_front();
    }
    return ans;
}
// MAX-heap
vector<int> sliding_window_max(vector<int> arr, int k) {
    vector<int> ans;
    priority_queue<int> heap;
    int i = 0;
    // insert 1st k-elements
    while (heap.size() < k) {
        heap.push(arr[i++]);
    }
    // push rest element ans find max
    while (i < arr.size()) {
        ans.push_back(heap.top());
        vector<int> temp;
        while (heap.size() > 1) {
            temp.push_back(heap.top());
            heap.pop();
        }
        // this is the least min so remove
        heap.pop();
        // now push k-1 elements back
        while (temp.size()) {
            heap.push(temp.back());
            temp.pop_back();
        }
        // push the current element to heap
        heap.push(arr[i++]);
    }
    ans.push_back(heap.top());
    return ans;
}
int main() {
    vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;
    vector<int> ans = sliding_window_max(arr, k);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    ans = sliding_window_max_deq(arr, k);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// Both of the above solution is not valid for 100%
vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // remove outof bound if present
        if (!dq.empty() and dq.front() == i - k) dq.pop_front();
        // mintain only Monotonically decreasing DQ;
        while (!dq.empty() and arr[dq.back()] < arr[i]) dq.pop_back();
        // push index to get the array directly ans measure the bound
        dq.push_back(i);
        // as soon as windows hit put max into ans; max always lies at head of DLL
        if (i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}