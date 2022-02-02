# Basic: O(nlong) sort and then k-1th index

import random
# you may not use random to choose pivot
def pivot(arr, l, r):
    p = random.randint(l, r) # choose any index between left and right index
    arr[p], arr[r] = arr[r], arr[p] # repalce with last element to select pivot
    p = arr[r] # select pivot which is at right
    i = l-1 # point to none i.e till now sorted array is none
    for j in range(l, r): # sort the array from l to r-1
        if arr[j] < p: # if any element is less than pivot then swap ith with jth to make array sorted till ith index
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    # as pivot will be next in sorted array so place it at i+1th index
    arr[i+1], arr[r] = arr[r], arr[i+1]
    # now array is sorted till i+1th index
    return i+1

def kth_small(arr, k):
    left, right = 0, len(arr) - 1
    # sort and find 
    while left <= right:
        # sort partially and get pivot index i.e last index of sorted part
        p = pivot(arr, left, right)
        # need to larger index
        if p < k:
            left = p + 1
        # need smaller index
        elif k < p:
            right = p - 1
        # found the required index
        else:
            return arr[p]


nums = [1,0,5,3,4, 8] # 0, 1, 3, 4, 5, 8
k  = 2              # kth-smallest
kl = len(nums) - k  # kth-largest element
print(kth_small(nums,  k-1))
print(kth_small(nums,  kl))