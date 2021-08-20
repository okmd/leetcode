import random

# default quick sort,loumuto partition
# take right as pivot and place it at its position. 
# less than < pivot < more than
# pivot index is returned.
def right_partition(arr, l, r):
    j = l
    i = l-1
    while j < len(arr)-1:
        if arr[j] < arr[r]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

        j += 1
    i += 1
    arr[i], arr[r] = arr[r], arr[i]
    return i

# take left as pivot, hoare partition
# do nothing for all element < pivot in LHS
# do nothing for all elements > pivot in RLS
# if i and j crossed or met the return j
# otherwise swap i and j
def left_partition(arr, l, r):
    pivot = arr[l]
    i = l-1
    j = r+1
    while True:
        i += 1
        while arr[i] < pivot:
            i += 1
        j -= 1
        while arr[j] > pivot:
            j -= 1
        if i >= j:
            return j
        arr[i], arr[j] = arr[j], arr[i]


# radomized version of loumuto
def loumuto_partition(arr, l, r):
    # Lomuto Partitioning
    p = random.randrange(l, r+1)
    arr[p], arr[r] = arr[r], arr[p]
    return right_partition(arr, l, r)

# randomized version of hoare
def hoare_partition(arr, l, r):
    p = random.randrange(l, r+1)
    arr[p], arr[l] = arr[l], arr[p]
    return left_partition(arr, l, r)


# quick sort hoare and lomuto
def quickSort(arr, l, r, h=True):
    if l >= r:
        return
    if h:
        p = hoare_partition(arr, l, r)
        # l to p not p-1 in left pivot
        quickSort(arr, l, p)
    else:
        p = loumuto_partition(arr, l, r)
        # l to p-1 in right pivot
        quickSort(arr, l, p-1)
    # right part is same for both
    quickSort(arr, p+1, r)


if __name__ == "__main__":
    arr = [5, 3, 7, 8, 9, 2, 4, 9, 0]
    quickSort(arr, 0, len(arr)-1)
    print(arr)

    arr = list(range(10))
    quickSort(arr, 0, len(arr)-1)
    print(arr)
