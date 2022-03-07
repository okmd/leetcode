#include <iostream>
#include <vector>
using namespace std;

class Stack {
   public:
    int top;
    int capacity;
    int *arr;
    Stack(int cap = 10) {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }
    int size() {
        return top + 1;
    }
    bool empty() {
        return size() == 0;
    }
    int full() {
        return size() == capacity;
    }
    bool insert(int val) {
        if (!full()) {
            arr[++top] = val;
            return true;
        } else {
            cout << "Overflow\n";
            return false;
        }
    }
    int peek() {
        if (!empty())
            return arr[top];
        cout << "Empty\n";
        return -1;
    }
    void pop() {
        if (!empty())
            top--;
        else
            cout << "Underflow\n";
    }
    void show() {
        for (int i = 0; i < size(); i++) {
            cout << "|" << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s = Stack(4);
    s.show();
    s.insert(4);
    s.show();
    s.pop();
    s.show();
    s.pop();
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout << s.peek() << endl;
    s.show();
    return 0;
}