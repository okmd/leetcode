# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
# from .heapify import max_heapify
from build_heap import *

# keep poping from the root as max
# maintain max heap
def heap_sort(arr):
    # extract max n times and heapify
    ans_sorted = []
    # as this passed by refrence, arr is heap
    # so root is maximum element
    arr = arr.copy()
    # from last index to root
    for i in range(len(arr)-1):
        # push the root to sorted ans
        ans_sorted.append(arr[1])
        # make root as last element
        arr[1] = arr[-1]
        # reduce the size of heap(exclude last element)
        arr = arr[:-1]
        # now heapify the new root
        max_heapify(arr, 1)
    return ans_sorted
    

if __name__ == "__main__":
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8]
    build_heap(arr)
    print(arr)
    print(heap_sort(arr))
    print(arr)
