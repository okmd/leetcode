#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue {
   public:
    int size;
    int capacity;
    int *arr;
    int front, rear;
    Queue(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        front = 0;
        rear = capacity - 1;
    }
    bool empty() {
        return size == 0;
    }
    bool full() {
        return size == capacity;
    }
    bool enqueue(int val) {
        if (!full()) {
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            size++;
            return true;
        }
        cout << "Overflow\n";
        return false;
    }
    int dequeue() {
        if (!empty()) {
            int item = arr[front];
            front = (front + 1) % capacity;
            size--;
            return item;
        }
        cout << "Underflow\n";
        return INT_MIN;
    }
    int get_rear() {
        if (!empty())
            return arr[rear];
        return INT_MIN;
    }
};
int main() {
    Queue q = Queue(4);
    q.enqueue(1);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.get_rear() << endl;
    return 0;
}
