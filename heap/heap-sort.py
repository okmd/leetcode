# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
# from .heapify import max_heapify
from build_heap import *

def heap_sort(arr):
    # extract max n times and heapify
    ans_sorted = []
    arr = arr.copy()
    for i in range(len(arr)-1):
        ans_sorted.append(arr[1])
        arr[1] = arr[-1]
        arr = arr[:-1]
        max_heapify(arr, 1)
    return ans_sorted
    

if __name__ == "__main__":
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8]
    build_heap(arr)
    print(arr)
    print(heap_sort(arr))
    print(arr)
