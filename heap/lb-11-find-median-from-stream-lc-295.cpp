// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    // Max heap | Min heap
    // min_heap <= max_heap <= 1+ min_heap
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    void max_heap_to_min(int val) {
        // current element is smaller than max of LHS
        int max_ele = max_heap.top();
        // so it should be place in LHS but can;t be inserted as LHS will have
        // 2 more element than RHS hence remove from LHS and then insert into LHS
        max_heap.pop();
        max_heap.push(val);
        min_heap.push(max_ele);
    }
    void min_heap_to_max(int val) {
        // current element is smaller than max of LHS
        int min_ele = min_heap.top();
        // so it should be place in LHS but can;t be inserted as LHS will have
        // 2 more element than RHS hence remove from LHS and then insert into LHS
        min_heap.pop();
        min_heap.push(val);
        max_heap.push(min_ele);
    }
    void insertHeap(int &x) {
        // first element will go into max-heap
        int mxs = max_heap.size();
        int mns = min_heap.size();
        // this is the 1st element
        if (mxs == 0) {
            max_heap.push(x);
        } else if (mns == mxs) {
            // both heap has same number of elements
            // if current element is less than all the elements of right side array.
            // push in left side as left side can contain 1 more element.
            if (x < min_heap.top()) {
                max_heap.push(x);
            } else {
                // current element is greator than smllest element of RHS
                // so it should be pushed in RHS but,
                // rhs can;t contain 1 more element hence remove from RHS and push to LHS
                // take the min element of RHS > max of LHS
                min_heap_to_max(x);
            }
        } else if (mns == 0) {
            // min heap is empty
            // current element is larger than max of LHS
            // push in minheap
            if (x > max_heap.top()) {
                min_heap.push(x);
            } else {
                max_heap_to_min(x);
            }
        } else if (x >= min_heap.top()) {
            min_heap.push(x);
        } else {
            // max heap > min heap size
            if (x < max_heap.top()) {
                // current element is smaller than max of LHS
                // so it should be place in LHS but can;t be inserted as LHS will have
                // 2 more element than RHS hence remove from LHS and then insert into LHS
                max_heap_to_min(x);
            } else {
                // more than max-heap top and less than min heap top
                min_heap.push(x);
            }
        }
    }

    // Function to balance heaps.
    void balanceHeaps() {
    }

    // Function to return Median.
    double getMedian() {
        int mns = min_heap.size();
        int mxs = max_heap.size();
        return (mxs > mns) ? double(max_heap.top()) : double((max_heap.top() + min_heap.top()) / 2);
    }
};
