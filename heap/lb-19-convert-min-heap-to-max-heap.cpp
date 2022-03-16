// Method 1:
// Idea: remove each element and insert into max heap
// heap pop + hepify = O(log n)
// heap push = O(log n)
// n nelement = O(n*logn) time and O(n) space

// Method 2:
// don;t care about the min-heap, consider it as raw array
// now create max-heap O(n) time
// leafs are already heaps -> n/2 -> n
// non leafs 1->n/2
// now keep heapify from n/2 to root => O(N);
// Looks like NlongN but amortized to O(n)
void MaxHeapify(int arr[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    // find largest
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        // swap and heapify child
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
void make_heap(int arr[], int n) {
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, n);
}