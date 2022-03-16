// given k arrays of size n
// find the smallest range having atleast one element in common.
// add first element of each list and find the range
// then find min range out of all ranges

// N = 5, K = 3
// KSortedArray[][] = {{1 3 5 7 9},
//                     {0 2 4 6 8},
//                     {2 3 5 7 11}}
// Output: 1 2
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Item {
   public:
    int row, col, val;
    Item(int i, int j, int v) {
        row = i;
        col = j;
        val = v;
    }
};
class Comp {
   public:
    bool operator()(Item i, Item j) {
        return i.val > j.val;
    }
};

class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // NOTE:GFG
        // vector<vector<int>> nums;
        // for (int i = 0; i < k; i++) {
        //     vector<int> temp;
        //     for (int j = 0; j < n; j++) {
        //         temp.push_back(arr[i][j]);
        //     }
        //     nums.push_back(temp);
        // }
        int range = INT_MAX;
        int max_element = INT_MIN;
        pair<int, int> ans;
        // row, col
        priority_queue<Item, vector<Item>, Comp> min_heap;
        // heap of all elements of 1s cols
        for (int i = 0; i < nums.size(); i++) {
            min_heap.push(Item(i, 0, nums[i][0]));
            max_element = max(max_element, nums[i][0]);
        }
        // find range
        while (1) {
            Item top = min_heap.top();
            min_heap.pop();
            // find min range start and end val
            if (range > max_element - top.val) {
                range = max_element - top.val;
                ans.first = top.val;
                ans.second = max_element;
            }
            // if lies in ranges
            if (top.row < nums.size() and top.col < nums[top.row].size() - 1) {
                top.col++;
                top.val = nums[top.row][top.col];
                min_heap.push(top);
                max_element = max(max_element, top.val);
            } else {
                // if anyone is execeeding the size of any row.
                break;
            }
        }
        vector<int> ans_vec = {ans.first, ans.second};
        return ans_vec;
    }
};