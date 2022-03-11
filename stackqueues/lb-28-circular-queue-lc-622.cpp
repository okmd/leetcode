// Given an array of fixed size
// implement circular queue in it
#include <iostream>
using namespace std;

class MyCircularQueue {
   public:
    int capacity;
    int size;
    int front;
    int rear;
    int *arr;
    MyCircularQueue(int cap) {
        capacity = cap;
        size = 0;
        front = 0;
        rear = capacity - 1;
        arr = new int[cap];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return capacity == size;
    }
    bool enQueue(int val) {
        // overflow
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        return true;
    }
    bool deQueue() {
        // underflow
        if (isEmpty()) return false;
        int ele = arr[front];
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    void show() {
        int f = front, r = rear;
        while (f != r) {
            cout << arr[f] << " ";
            f = (f + 1) % capacity;
        }
        cout << arr[f];
        cout << endl;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    MyCircularQueue cq(3);
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    cq.enQueue(4);
    cq.show();
    cout << cq.size << endl;
    cq.deQueue();
    cq.show();
    cout << cq.size << endl;
    cq.enQueue(4);
    cq.show();
    cout << cq.Front() << " " << cq.Rear() << endl;
    return 0;
}
