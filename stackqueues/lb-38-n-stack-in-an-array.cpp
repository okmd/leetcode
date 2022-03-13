// Implement k stack in single array

// Method 1; divide array of size n/k each for stack size.
// Method 2:
#include <bits/stdc++.h>
using namespace std;
class Kstack {
   public:
    int n;  // capacity of stack
    // how many stacks in single array
    int k;
    // single array
    int *arr;
    // maintain next for push and prev for pop
    int *next_prev;
    // maintain k tops of arrays.
    int *tops;
    int free_index;
    Kstack(int n, int k) {
        this->n = n;
        this->k = k;
        free_index = 0;
        arr = new int[n];
        tops = new int[k];
        next_prev = new int[n];
        // base case
        // initialize all tops to -1 and next_free index of each cell
        for (int i = 0; i < k; i++) tops[i] = -1;
        int i;
        for (i = 0; i < n - 1; i++) {
            // 0th index has next free space 1
            next_prev[i] = i + 1;
        }
        next_prev[i] = -1;  // last index of array does not have any next free space;
    }
    bool full() {
        return (free_index == -1);
    }
    bool empty(int stack) {
        return (tops[stack] == -1);
    }
    bool push(int stack, int value) {
        if (full()) return INT_MAX;
        int index = free_index;
        free_index = next_prev[index];   // update to next free index of array
        next_prev[index] = tops[stack];  // update the prev index in next_prev array, usefull when pop
        tops[stack] = index;             // new top of stack is where is element is going to be inserted.
        arr[index] = value;              // insert value @ index in array where top points.
        return true;
    }
    int pop(int stack) {
        if (empty(stack)) return INT_MIN;
        int top = tops[stack];         // get the top index of current stack
        tops[stack] = next_prev[top];  // update top to prev_element of stack as current element is going to be removed
        next_prev[top] = free_index;   // next free space current index top(as current free_index points to next location).
        free_index = top;              // now free index is top as the element is deleted
        return arr[top];               // return top of current stack
    }
};
int main() {
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    Kstack ks(n, k);

    // Let us put some items in stack number 2
    ks.push(2, 15);
    ks.push(2, 45);

    // Let us put some items in stack number 1
    ks.push(1, 17);
    ks.push(1, 49);
    ks.push(1, 39);

    // Let us put some items in stack number 0
    ks.push(0, 11);
    ks.push(0, 9);
    ks.push(0, 7);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}