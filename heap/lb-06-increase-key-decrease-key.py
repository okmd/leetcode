# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
# from .heapify import max_heapify
from build_heap import *

# for max heap -> increase key -> move up
# for min heap -> increase key -> move down
def increase_key(arr, i, key):
    # if key less and u wnat to increase
    if key < arr[i]:
        return "Should be greator"
    # increase and percolate up
    arr[i] = key
    while i>1 and arr[i//2] < arr[i]:
        arr[i], arr[i//2] = arr[i//2], arr[i]
        i = i//2


# for max heap -> decrease key -> move down
# for min heap -> decrease key -> move up
def decrease_key(arr, i, key):
    if key > arr[i]:
        return "Should be less"
    arr[i] = key
    # percolate down
    max_heapify(arr, i)

if __name__ == "__main__":
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8]
    build_heap(arr)
    print(arr)
    increase_key(arr, 3, 20)
    print(arr)
    decrease_key(arr, 1, 7)
    print(arr)
