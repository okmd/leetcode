# the steps involved in merge sort are
# 1. binary spilt the array into two parts
# 2. sort individual and then merge two sorted array to combine sibgle sorted array
def merge(arr, l, m, r):
    # O(size of arr1 * size of arr2)
    i = l
    while i <= m:
        j = m+1
        if arr[i] > arr[j]:
            arr[i], arr[j] = arr[j], arr[i]
            while j < r and arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                j += 1
        i += 1


def merge_sort_helper(arr, l, r):
    if l < r:
        mid = l + (r-l)//2
        merge_sort_helper(arr, l, mid)
        merge_sort_helper(arr, mid+1, r)
        merge(arr, l, mid, r)


def merge_sort(arr):
    merge_sort_helper(arr, 0, len(arr)-1)
    return arr

def merge_iterative(arr):
    pass


if __name__ == "__main__":
    print(merge_sort([4, 5, 3, 2, -1]), sorted([4, 5, 3, 2, -1]))
    print(merge_sort([94, -95, 300, 892, 885, -71]), sorted([94, -95, 300, 892, 885, -71]))
    print(merge_sort([4, 85, 43, 278, 905, 8071]), sorted([4, 85, 43, 278, 905, 8071]))
    print(merge_sort([i for i in range(20)]), [i for i in range(20)])
