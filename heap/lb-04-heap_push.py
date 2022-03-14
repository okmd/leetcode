# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
# from .heapify import max_heapify
from build_heap import *

# PERCOLATE UP
def heap_push(arr, val):
    # index of last inserted element
    i = len(arr)
    # insert that element
    arr.append(val)
    # percolate up -> move parent to parent
    # if parent is less than then swap with parent
    # and keep repeating the same till the root node
    while i>1 and arr[i//2] < arr[i]:
        arr[i//2], arr[i] = arr[i], arr[i//2]
        i = i//2


if __name__ == "__main__":
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8]
    build_heap(arr)
    print(arr)
    heap_push(arr, 9)
    print(arr)
