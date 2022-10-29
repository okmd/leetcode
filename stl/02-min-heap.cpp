#include<iostream>
using namespace std;

class PQ {
public:
    int* arr;
    int size;
    PQ(int s) {
        arr = new int[s];
        size = 0;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i+1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        // change sign to convert to min-heap
        if (l < size and arr[l] < arr[largest]) largest = l;
        if (r < size and arr[r] < arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify_down(largest);
        }
    }
    void heapify_up(int i) {
        int p = parent(i);
        // > for min-heap
        if (i and arr[p] > arr[i]) {
            swap(arr[i], arr[p]);
            heapify_up(p);
        }
    }
    void push(int val) {
        arr[size++] = val;
        heapify_up(size - 1);
    }
    void pop() {
        arr[0] = arr[--size];
        heapify_down(0);
    }
    int top() {
        return arr[0];
    }
    ~PQ() {
        delete[]arr;
    }
};
int main() {
    PQ pq(10);

    // Note: The element's value decides priority

    pq.push(3);
    pq.push(2);
    pq.push(15);

    cout << "Size is " << pq.size << endl;

    cout << pq.top() << "\n ";
    pq.pop();

    cout << pq.top() << ";\n";
    pq.pop();

    pq.push(5);
    pq.push(4);
    pq.push(45);

    cout << endl << "Size is " << pq.size << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    std::cout << pq.size;
}