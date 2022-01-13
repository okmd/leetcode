# given an array of size n
# partition into two sets having same sum.
# Solution:
# 1. problem can be reduced into two sets only in the sum is even.
# 2. then problem reduced to finding if sum/2 can be found in given in the array.

def partition_equal_subset(arr):
    n = len(arr)
    sm = sum(arr)
    if sm&1:
        return False
    req_sum = int(sm//2)
    dp = [[0]*(req_sum+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(req_sum+1):
            if i==0:
                dp[i][j] = False
            elif j==0:
                dp[i][j] = True
            elif arr[i-1]> j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]] # not included or included
                
    return dp[n][req_sum]
    
    
arr = [1,5,5,11]
print(partition_equal_subset(arr))
                
    