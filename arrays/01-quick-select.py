# idea is to find the k-smallest and larget element in unsorted array
# other methods are - sorting, BST, min/max heap, hashmap
# pivot finding is same as quicksort
#### NOTE: kth smallest element is at: k-1 index
#### NOTE: kth largest element is at: n-k index.
def pivot(arr, l, r):
    p = arr[r]
    i = l-1
    for j in range(l, r):
        if arr[j] < p:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[r] = arr[r], arr[i+1]

    return i+1


# quick select.
def qs_small(arr, left, right, k):
    # if k is negative then return
    # or if num of elements in the array are less than k
    if k > 0 and right-left+1 >= k:
        # find the index of pivot
        # all elemets in left of arr[p] are smaller and right are larger.
        p = pivot(arr, left, right)
        # print(l, r, k, p, arr[p])
        # if element at p+1 is kth element w.r.t to left
        # kth element from 0 is at k-1 index,
        # kth element from 1 is k,
        # kth element from 2 is k+1, similary
        # kth element from left is k+left-1,
        # if pivot is at kth element then return
        if p == k+left-1:
            return arr[p]
        # if pivot is less than kth element then search in right.
        if p < k+left-1:
            # we need to modify k w.r.t left as well
            # we have p-left+1 numbers of elements already in left of arr that we ignored.
            # ṇow remaining elements to be found is k-ignored = k-(p-left+1)
            return qs_small(arr, p+1, right, k-(p-left+1))
        # else sarch in left
        return qs_small(arr, left, p-1, k)


def qs_large(arr, left, right, k):
    return qs_small(arr, left, right, len(arr)-k+1)


if __name__ == "__main__":
    arr = [7, 6, 1, 0, 2, 5, 3, 4, 55, 62, 12]
    print(arr)
    for k in range(1, len(arr)+1):
        print(f"{k:02}th smallest element is: ", end=" ")
        print(qs_small(arr, 0, len(arr)-1, k))
    print("")
    arr = [7, 6, 1, 0, 2, 5, 3, 4, 55, 62, 12]
    for k in range(1, len(arr)+1):
        print(f"{k:02}th largest element is: ", end=" ")
        print(qs_large(arr, 0, len(arr)-1, k))
