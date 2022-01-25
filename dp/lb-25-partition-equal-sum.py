
def dp_memoization(arr, n):
    sm = sum(arr)
    if sm&1:
        return False 
    req_sum = int(sm/2)
    dp = [[-1]*(req_sum+1) for _ in range(n+1)]
    
    def helper(arr, req_sum, n):
        if req_sum ==0:
            return True
        
        if n<0:
            return False
        
        if dp[n][req_sum]!=-1:
            return dp[n][req_sum]
        
        if arr[n-1] > req_sum:
            dp[n][req_sum] =  helper(arr, req_sum, n-1)
            return dp[n][req_sum]
        
        dp[n][req_sum] = helper(arr, req_sum , n-1) or  helper(arr, req_sum - arr[n-1], n-1)
        return dp[n][req_sum]

    return helper(arr, req_sum, n)

def equalPartition(arr, n):
    sm = sum(arr)
    if sm&1:
        return False
    req_sum = int(sm//2)
    dp = [[0]*(req_sum+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(req_sum+1):
            if i==0:
                dp[i][j] = False
            elif j==0:# required sum is 0 then always possible irrespective of available numbers.
                dp[i][j] = True
            elif arr[i-1]> j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]] # not included or included
                    
    return dp[n][req_sum]

arr = [1,5,2,0] #[478, 757, 314, 471, 729, 100, 459, 618]
# print(sum(arr), sum(arr)/2)
n = len(arr)
print(dp_memoization(arr, n))
print(equalPartition(arr, n))