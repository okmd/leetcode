# You are given the nums of array.
# you need to find the longest increasing subsequence.
# There are more than one method to find the ans
# Recursion and backtracking.

# O(exponential)
def rec_backtracking(arr):
    pass

# O(n^2)
def dp_tabulation(arr):
    n = len(arr)
    lis = [1]*n
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                lis[i] = max(1 + lis[j], lis[i])
    return max(lis)

# the problem can be reduced to lcs i.e longest common subsequence by creating a new sequence by sorting.
# it is guranteed to get lcs in both sorted and non sorted array.


#https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)
def binary_bisect(arr, num):
    if len(arr)==1:
        return 0
    
    l = 0
    r = len(arr)-1
    while l<r:
        mid = l + (r-l)//2
        if arr[mid]<num and arr[mid+1]>num:
            return mid
        elif arr[mid]>num:
            r = mid-1
        else:
            l = mid+1
    return r+1
        
    

def dp_binary_greedy(arr):
    lis = []
    for num in arr:
        if len(lis)==0 or lis[-1]<num:
            lis.append(num)
        else:
            idx = binary_bisect(lis, num)
            lis[idx]=num
            
    return len(lis)
        


arr = [10, 9, 2, 5, 3, 7, 101, 18] # 4
print(dp_tabulation(arr))
# rec_backtracking(arr)
print(dp_binary_greedy(arr))
