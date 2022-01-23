# Given array of n numbers
# find subsequence with max sum such that no two adj element come together.

dp = [-1]*(10**4 + 5)
def recursive(arr, n):
    if n<0:
        return 0
    if dp[n]!=-1:
        return dp[n]
    # including current element
    dp[n] = max(arr[n] + recursive(arr, n-2), recursive(arr, n-1))
    #excluding current element
    return dp[n]
    

def dp_tabulation(arr, n):
    dp = [0]*(n+2)
    dp[0] = 0
    dp[1] = 0
    for i in range(2, n+2):
        dp[i] = max(arr[i-2] + dp[i-2], dp[i-1])
       
    return dp[n+1]

def dp_tabulation1(arr, n):
    dp = [0]*(n+2) # make extra 0's at end
    if n>=1:
        dp[0] = arr[0]
    for i in range(1, n):
        dp[i] = max(arr[i] + dp[i-2], dp[i-1]) #-index dp will take 0 from end
        
    return dp[n-1]


arr = [5,5,10,100,10,5] # 110
n = len(arr)
print(recursive(arr, n-1))
print(dp_tabulation(arr, n))
print(dp_tabulation1(arr, n))