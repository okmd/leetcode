#include<iostream>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}
bool compare(float a, float b) {
    return a < b;
}
class point {
public:
    int a, b;
    point(int x, int y) {
        a = x;
        b = y;
    }
    point() {
        a = 0, b = 0;
    }
    void show() {
        cout << "(" << a << ", " << b << ") ";
    }
};
bool compare(point p1, point p2) {
    return p1.a < p2.a;
}

template<typename T>
class PQ {
public:
    T* arr;
    int size;
    bool (*compare)(T, T);
    PQ(int s, bool (*fun)(T, T)) {
        arr = new T[s];
        size = 0;
        compare = fun;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size and compare(arr[l], arr[largest])) largest = l;
        if (r < size and compare(arr[r], arr[largest])) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify_down(largest);
        }
    }
    void heapify_up(int i) {
        int p = parent(i);
        if (i and !compare(arr[p], arr[i])) {
            swap(arr[i], arr[p]);
            heapify_up(p);
        }
    }
    void push(T val) {
        arr[size++] = val;
        heapify_up(size - 1);
    }
    void pop() {
        arr[0] = arr[--size];
        heapify_down(0);
    }
    T top() {
        return arr[0];
    }
    ~PQ() {
        delete[]arr;
    }
};
int main() {
    PQ<float> pq(10, &compare);
    pq.push(3);
    pq.push(2);
    pq.push(15.4);

    cout << "Size is " << pq.size << endl;

    cout << pq.top() << "\n ";
    pq.pop();

    cout << pq.top() << ";\n";
    pq.pop();

    pq.push(15.5);
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

    /// P
    PQ<point> pq1(10, &compare);
    pq1.push(point(1, 2));
    cout << pq1.size << endl;
    pq1.top().show();

    return 0;
}