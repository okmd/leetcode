# Given two sorted array
# find median of them
# METHOD 0: merge and sort. O(KlogK), k = n+m
# METHOD 1: use merge technique to create a sorted array and find median. O(m+n)
# METHOD 2: do not store as in methon 1, just mainaintain the count when count become middle you have reached media. O(m+n) and O(1) space.
# METHOD 3: Binary seach O(log(m+n)), O(1)
def median(arr):
    if not len(arr):
        return 0
    n2 = len(arr)//2
    if len(arr) & 1:
        return arr[n2]
    return (arr[n2 - 1] + arr[n2])/2

# O((n+m)log(n+m)) and O(n+m)
def merge_single(arr1, arr2):
    temp = []
    for i in arr1:
        temp.append(i)
    for i in arr2:
        temp.append(i)
    temp.sort()

    return median(temp)

# O(n+m) and O(n+m)
def merge_sort_technique(arr1, arr2):
    temp = []
    i = 0
    j = 0
    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            temp.append(arr1[i])
            i += 1
        else:
            temp.append(arr2[j])
            j += 1

    while i < len(arr1):
        temp.append(arr1[i])
        i += 1

    while j < len(arr2):
        temp.append(arr2[j])
        j += 1

    return median(temp)

# O(n+m) and O(1)
def merge_with_constant(arr1, arr2):
    n12 = len(arr1) + len(arr2)
    count = n12//2+1
    mid = [0]*2
    index = 0
    i = 0
    j = 0
    while count and i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            mid[index] = arr1[i]
            i += 1
        else:
            mid[index] = arr2[j]
            j += 1
        index = (index+1) % 2  # or index = not index
        count -= 1
        # print(count ,index, mid)

    while count and i < len(arr1):
        mid[index] = arr1[i]
        index = not index
        i += 1
        count -= 1

    while count and j < len(arr2):
        mid[index] = arr2[j]
        j += 1
        index = not index
        count -= 1

    if n12 & 1:
        return max(mid)
    return sum(mid)/2

# O(log min(n+m)) and O(1)
# IDEA: is to partitions left and right array such that both combined array is half sorted till median.
# just find median using left sorted half.
def binary_searach_optimized(A, B):
    n = len(A)
    m = len(B)
    if n>m:
        return helper(B,A)
    low = 0
    high = n
    sorted_left_size = (n+m+1)//2 # left will have 1 more element in case of odd length
    while low<=high:
        mid = low + (high-low)//2
        sizeA = mid
        sizeB = sorted_left_size - sizeA
        # overflow
        leftA = A[sizeA-1] if sizeA>0 else float('-inf')
        rightA = A[sizeA] if sizeA<n else float('inf')
        leftB = B[sizeB-1] if sizeB>0 else float('-inf')
        rightB = B[sizeB] if sizeB<m else float('inf')
        
        if leftA<= rightB and leftB <= rightA:
            # if odd length then max of left size of both array will be extream right of left sorted array hence median.
            if (n+m)&1:
                return max(leftA, leftB)
            # if even then mean of max left and min right of both array.
            return (max(leftA, leftB) + min(rightA, rightB))/2
        elif leftA > rightB:
            high = mid - 1
        else:
            low = mid+1
    return 0

    # check sor


arr1 = [1, 12, 14, 15]
arr2 = [1, 2, 3, 4, 9, 11]
print(merge_single(arr1, arr2))
print(merge_sort_technique(arr1, arr2))
print(merge_with_constant(arr1, arr2))
print(binary_searach_optimized(arr1, arr2))
