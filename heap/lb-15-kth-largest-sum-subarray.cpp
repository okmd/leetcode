// {1,2,3} => {1,12, 123}, {2,23}, {3}
// total possible sub-arrays: n+n-1+...1 = n(n+1)/2
// Bruteforce method find all sub-arrays and push there sum in heap
// then find kth largest or smallest

// Optimization:
// by using the running sum i.e find find the cumulative sum of each index
// then range sum can easily be computed as sm[j]-sm[i-1]
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kth_largest_sum(int arr[], int n, int k) {
    // beyond the possible subarrays
    if (k > (n * (n + 1) / 2.0)) return INT_MAX;
    int sum[n + 1] = {0};
    // find cum sum
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i - 1];
    }
    // min-heap
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sub_array_sum = sum[j] - sum[i - 1];
            // maintain a minheap of size k
            // so it will maintain the max-k sub array sums
            // if less than k
            if (heap.size() < k) {
                heap.push(sub_array_sum);
            } else if (heap.top() < sub_array_sum) {
                // if sum greator than k largest sum comes then useful else not.
                // remove the least sum in k-largest sums as this sum can be kth largest
                heap.pop();
                // now push it ti min heap
                heap.push(sub_array_sum);
                // now top of min heap will contain the kth-largest element.
                // as all the least large will be below root, less than kth largest
                // but acutally their amplitude is large.
            }
        }
    }
    return heap.top();
}

int main() {
    int arr[] = {10, -10, 20, -40};
    int n = sizeof(arr) / sizeof(int);
    int k = 6;
    cout << kth_largest_sum(arr, n, k) << endl;
    return 0;
}
