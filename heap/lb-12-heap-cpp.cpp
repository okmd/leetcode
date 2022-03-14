#include <algorithm>  // all heap functions
#include <iostream>
#include <vector>
using namespace std;
// In C++ STL, there is priority_queue that can directly be used to implement Max Heap
int main() {
    vector<int> v = {20, 30, 40, 25, 15};
    // create max heap
    make_heap(v.begin(), v.end());
    // get max of heap
    cout << v.front() << endl;
    // heap push and heapify as heap_push
    v.push_back(400);
    push_heap(v.begin(), v.end());
    cout << v.front() << endl;
    // heap pop then it can be popped
    pop_heap(v.begin(), v.end());
    v.pop_back();
    cout << v.front() << endl;
    // using is_heap()
    bool ans = is_heap(v.begin(), v.end());
    cout << ((ans) ? "Heap\n" : "Not heap\n");

    // using is_heap_until() to check position
    // till which container is heap
    auto it = is_heap_until(v.begin(), v.end());
    cout << *it << endl;

    // Displaying heap range elements
    cout << "The heap elements in container are : ";
    for (auto it1 = v.begin(); it1 != it; it1++)
        cout << *it1 << " ";

    // sorting heap using sort_heap()
    cout << endl;
    sort_heap(v.begin(), v.end());
    for (auto it1 = v.begin(); it1 != v.end(); it1++)
        cout << *it1 << " ";

    return 0;
}

// Note: Heap functions are present in algorithm headerfile
// queue headerfile has priority_queue same can be used to create min/max heap