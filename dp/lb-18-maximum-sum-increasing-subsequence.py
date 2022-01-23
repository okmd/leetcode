# You are given the array of positive integer.
# find the increasing subsequence with maximum sum.

def dp_tabulation(arr, n):
    lis = arr.copy() # initially individual element is sum
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]: # if increasing
                lis[i] = max(lis[i], lis[j] + arr[i]) # if already greator sum ignore, else add current element to the lis of previous inc element.
    return max(lis)
        

arr = [1,101, 2, 3, 100]
print(dp_tabulation(arr.copy(), len(arr)))
arr = [1, 101, 2, 3, 200]
print(dp_tabulation(arr.copy(), len(arr)))