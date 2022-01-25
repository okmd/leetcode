# Given list of n integers.
# need to find the subarray which has maximum sum.
# only sum is required.

# Method 1: Brute force, use two loop to make all subarrays and third loop to find sum of array. O(n3)
import sys

def brute_force(arr):
    n = len(arr)
    mx = -sys.maxsize
    for i in range(n):
        for j in range(i, n):
            sm = 0
            for k in range(i,j+1):
                sm += arr[k]
            mx = max(mx, sm)
    return mx

def optimization1(arr):
    n = len(arr)
    mx = -sys.maxsize
    for i in range(n):
        sm = 0
        for j in range(i, n):
            sm += arr[j]
            mx = max(mx, sm)
    return mx

# dp and kadane's algorithm
# Kdane algorithm is used to find maximum subset sum in o(n).
# at starting max_ending_here[meh] = max_so_far[msf] = arr[0]
# at any point max_ending_here = max(arr[i], max_ending_here + arr[i])
# update the max_so_far, if got another maximum.
def kadane(arr):
    meh, msf = arr[0], arr[0]
    for i in range(1, len(arr)):
        meh += arr[i]
        if meh<0:
            meh = 0
        if msf<meh:
            msf = meh
    return msf

def max_subset_sum(arr):
    meh = msf = arr[0]
    for i in range(1, len(arr)):
        meh = max(arr[i], meh + arr[i])
        msf = max(meh, msf)
    return msf

# modification in original array
# if making a copy then O(n) space and time complexity
def optimization2(arr):
    for i in range(1, len(arr)):
        arr[i] += arr[i-1] if arr[i-1]>0 else 0
    return max(arr)        
            
    
           
arr = [1,2,3,-2,5]#[-2,-3, 4,-1,-2,1,5,-3]
print(brute_force(arr)) 
print(optimization1(arr)) 
print(kadane(arr)) 
print(max_subset_sum(arr))
print(optimization2(arr)) 