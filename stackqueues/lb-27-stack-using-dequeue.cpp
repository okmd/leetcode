// De-queue is a data structure where insert and delete operation can be done
// in both ends of queue in O(1) time.

// DLL with head and tail pointer
//  DEQUEUE             STACK           QUEUE
// Insert_first()       -               -
// insert_last()        push            enqueue
// remove_fist          -               dequeue
// remove_last          pop             -

#include <deque>
#include <iostream>
using namespace std;

class Stack {
   public:
    deque<int> dq;
    void push(int val) {
        dq.push_back(val);
    }
    int pop() {
        if (dq.empty()) return -1;
        int val = dq.back();
        dq.pop_back();
        return val;
    }
    int size() {
        return dq.size();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    cout << s.pop() << endl;
    s.push(5);
    s.push(7);
    cout << s.pop() << endl;
    cout << s.size() << endl;
}
// DeQ can be implemented using the doubly linked list
// with head and tail pointer
// insert and delete at head
// insert and delete from tail