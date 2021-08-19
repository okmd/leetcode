# merging two sorted arrays.

# METHOD 1: Brute force
# given two sorted array of size m and n.
# create a new array of size m+n
# copy all elements from both array to combined one
# sort the combined array
# copy back to original array
# O(nlong)

# METHOD 2: Using insertion sort technique
# time complexity : O(mn)

# METHOD 3:
# 2 pointer technique
# with O(1) space
# when arr1 is padded with 0 other number of elements times.

# with O(n) space
# create an extra array and copy to them.

def method1(arr1, arr2):
    temp = []  # size m+n
    for i in arr1:
        temp.append(i)
    for i in arr2:
        temp.append(i)
    # sort
    temp = sorted(temp)
    # after sorting these elemets can be placed into original array which is to be merged
    for i in range(len(arr1)):
        arr1[i] = temp[i]
    for i in range(len(arr2)):
        arr2[i] = temp[i+len(arr1)]

    # print
    print(arr1)
    print(arr2)


def method2(arr1, arr2):
    i = 0
    while i < len(arr1):
        j = 0
        if arr1[i] > arr2[j]:
            arr1[i], arr2[j] = arr2[j], arr1[i]
            # sort the arr2 as new element is inserted into it
            while j < len(arr2)-1 and arr2[j] > arr2[j+1]:
                arr2[j], arr2[j+1] = arr2[j+1], arr2[j]
                j += 1
        i += 1
    print(arr1)
    print(arr2)


def merge_for_merge_sort(arr, l, m, r):
    # assuming mid in left side
    # O(nm) using selection sort technique
    i = l
    while i <= m:
        j = m+1
        if arr[i] > arr[j]:
            arr[i], arr[j] = arr[j], arr[i]
            while j < r and arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                j += 1
        i += 1


def method3(arr1, arr2):
    # extra space
    temp = []
    i, j = 0, 0
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            temp.append(arr1[i])
            i += 1
        else:
            temp.append(arr2[j])
            j += 1

    if i == len(arr1):
        for j in range(j, len(arr2)):
            temp.append(arr2[j])
    else:
        for j in range(j, len(arr1)):
            temp.append(arr1[j])
    print(temp)


def method3_padded_0(arr1, arr2, m, n):
    i = m-1
    j = n-1
    end = m+n - 1
    while j >= 0:
        if i >= 0 and arr1[i] > arr2[j]:
            arr1[end] = arr1[i]
            i -= 1
        else:
            arr1[end] = arr2[j]
            j -= 1
        end -= 1

    # all the elements are sorted in this array itself
    print(arr1)


if __name__ == "__main__":
    arr1 = [1, 5, 6, 9]
    arr2 = [0, 1, 6, 99]
    print(f"Original: {arr1} and {arr2}")
    # method1(arr1, arr2)
    # method2(arr1, arr2)
    arr = [4, 5, 6, 7, 11, 0, 2, 4, 6, 7, 9]
    print(arr)
    merge_for_merge_sort(arr, 0, 4, len(arr)-1)
    print(arr)

    method3(arr1, arr2)
    method3_padded_0([1, 2, 3, 4, 5, 0, 0, 0], [1, 5, 7], 5, 3)
