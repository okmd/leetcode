// Implement k queue in single array

// Method 1; divide array of size n/k each for queue size.
// Method 2:
#include <bits/stdc++.h>
using namespace std;
class Kqueue {
   public:
    int n;  // capacity of queue
    // how many stacks in single array
    int k;
    // single array
    int *arr;
    // maintain next for push and prev for pop
    int *next_prev;
    // maintain k fronts and rears of queues.
    int *fronts;
    int *rears;
    int free_index;
    Kqueue(int n, int k) {
        this->n = n;
        this->k = k;
        free_index = 0;
        arr = new int[n];
        fronts = new int[k];
        rears = new int[k];
        next_prev = new int[n];
        // base case
        // initialize all fronts to -1 and next_free index of each cell
        for (int i = 0; i < k; i++) fronts[i] = -1;
        for (int i = 0; i < n - 1; i++) {
            // 0th index has next free space 1
            next_prev[i] = i + 1;
        }
        next_prev[n - 1] = -1;  // last index of array does not have any next free space;
    }
    bool full() {
        return (free_index == -1);
    }
    bool empty(int queue) {
        return (fronts[queue] == -1);
    }
    bool enqueue(int queue, int value) {
        if (full()) return false;
        int index = free_index;
        free_index = next_prev[index];  // update to next free index of array
        if (empty(queue)) {
            fronts[queue] = index;  // if empty then front will be current index value
        } else {
            next_prev[rears[queue]] = index;  // when current rear is deleted then this index would be the front.
        }
        next_prev[index] = -1;  // this is the last one inserted hence its front will be -1 when current element is deleted.
        rears[queue] = index;   // new rear of queue is where is element is going to be inserted.
        arr[index] = value;     // insert value @ index in array where rear points.
        return true;
    }
    int dequeue(int queue) {
        if (empty(queue)) return INT_MIN;
        int front = fronts[queue];         // get the front index of current queue
        fronts[queue] = next_prev[front];  // as next_prev contains the front value when this element is deleted
        next_prev[front] = free_index;     // next free space the free spance pointed by free_index.
        free_index = front;                // now free_index is front as the element is deleted hence it is now free space;
        return arr[front];                 // return front of current queue
    }
};
int main() {
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    Kqueue ks(n, k);

    // Let us put some items in queue number 2
    ks.enqueue(2, 15);
    ks.enqueue(2, 45);

    // Let us put some items in queue number 1
    ks.enqueue(1, 17);
    ks.enqueue(1, 49);
    ks.enqueue(1, 39);

    // Let us put some items in queue number 0
    ks.enqueue(0, 11);
    ks.enqueue(0, 9);
    ks.enqueue(0, 7);

    cout << "Popped element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Popped element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Popped element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}