from array import array
# find element in a rotated sorted array.
#   -> find pivot index
#   -> split into two parts and apply binary search into subpart.


def binarySearch(arr, l, r, key):
    while l <= r:
        mid = l + (r-l)//2
        if arr[mid] == key:
            return mid
        if arr[mid] > key:
            r = mid-1
        else:
            l = mid+1
    return -1


def binarySearchRec(arr, l, r, key):
    if r < l:
        return -1
    mid = l + (r-l)//2
    if arr[mid] == key:
        return mid
    if arr[mid] > key:
        return binarySearchRec(arr, l, mid-1, key)
    return binarySearchRec(arr, mid+1, r, key)


# a = [1, 2, 3, 4, 5, 6]
# print(binarySearch(a, 0, len(a)-1, 14))
# print(binarySearchRec(a, 0, len(a)-1, 14))

def rotatedBinarySearch(arr, l, r, key):
    if l > r:
        return -1
    mid = (l+r)//2
    if arr[mid] == key:
        return mid
    if arr[l] <= arr[mid]:
        # sorted part
        # if element lies in the left part
        if arr[l] <= key and arr[mid] >= key:
            return rotatedBinarySearch(arr, l, mid-1, key)
        # otherwise lies in the right part
        return rotatedBinarySearch(arr, mid+1, r, key)
    # else is default as both are return in the above if.
    if arr[r] >= key and key >= arr[mid]:
        return rotatedBinarySearch(arr, mid+1, r, key)
    return rotatedBinarySearch(arr, l, mid-1, key)


arr = [6, 7, 8, 1, 2, 3, 4, 5]
key = int(input("Enter Element to be found? "))
index = rotatedBinarySearch(arr, 0, len(arr)-1, key)
print(f"Element {key} is found at {index}.")
