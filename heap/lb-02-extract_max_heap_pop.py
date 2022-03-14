# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
# from .heapify import max_heapify
from build_heap import *


def extract_max(arr):
    # if empty as one based indexing 
    if len(arr) < 1:
        return "Underflow"
    # max of heap
    max_ele = arr[1]
    # make last element as root
    arr[1] = arr[-1]
    # remove last element
    arr = arr[:-1]
    # now heapify the root
    max_heapify(arr, 1)
    # now print the new heap
    print(arr)
    # maximum of heap
    return max_ele


if __name__ == "__main__":
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8]
    # first create the heap
    build_heap(arr)
    # print the heap
    print(arr)
    # extract max of heap, i.e remove and heapify
    print(extract_max(arr))
