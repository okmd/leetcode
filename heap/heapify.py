# Heap is the CBT i.e all the leaf nodes are present at the last level or second last level.
# Heapify is same as PERCOLATE DOWN this is done in decrease key.
# NOTE: This code is 1 based indexing heap.

def max_heapify(arr, i):
    left_child = 2*i
    right_child = 2*i+1
    larger = i
    if left_child < len(arr) and arr[left_child] > arr[i]:
        larger = left_child
    if right_child < len(arr) and arr[right_child] > arr[larger]:
        larger = right_child
    if i!=larger:
        arr[i], arr[larger] = arr[larger], arr[i]
        max_heapify(arr, larger)



if __name__ == "__main__":
    arr = [-1, 1,2,3,4,5,6,7,8]
    max_heapify(arr, 1)
    print(arr)