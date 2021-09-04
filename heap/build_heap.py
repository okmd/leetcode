# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.
# build heap = O(n) i.e heapify non leaf nodes only
# 1 to ceil(n/2) are non-leaf and ceil(n/2) to n are leaf nodes.
from heapify import max_heapify

def build_heap(arr):
    i = len(arr)//2
    while i>0:
        max_heapify(arr, i)
        i -= 1


if __name__ == "__main__":
    arr = [-1, 1,2,3,4,5,6,7,8]
    build_heap(arr)
    print(arr)