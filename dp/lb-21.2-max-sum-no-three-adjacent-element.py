# Given array of n numbers
# find subsequence with max sum such that no two adj element come together.

dp = [-1]*(10)
def recursive(arr, n):
    if n<0:
        return 0
    if n==0:
        return arr[n]
    if n==1:
        return arr[n-1] + arr[n]
    if dp[n]!=-1:
        return dp[n]
    # exclude, include, include current and previous
    dp[n] = max(recursive(arr, n-1), arr[n] + recursive(arr, n-2), arr[n] + arr[n-1] + recursive(arr, n-3)) 
    # exclude nth, include nth and exculde n-1th, include nth, n-1th and exculde n-2th then find for remaining.
    return dp[n]
    

def dp_tabulation(arr, n):
    dp = [0]*(n+1)
    dp[0] = 0
    if n>=1:
        dp[1] = arr[0]
    if n>=2:
        dp[2] = arr[0] + arr[1]
        
    for i in range(3, n+1):
        j = i-1 # as index in array is less than 1
        dp[i] = max(dp[i-1], # exclude ith element which is at i-1 index in arr
                    arr[j] + dp[i-2], # include ith@i-1 in arr, exclude i-1th @i-2 in arr, then find for i-2@dp
                    arr[j]+ arr[j-1] + dp[i-3]) # include at ith@i-1, i-1@i-2, exclude i-2th@i-3, find for dp 
       
    return dp[n]

def dp_tabulation1(arr, n):
    dp = [0]*(n+5)
    dp[0] = 0
    if n>=1:
        dp[1] = arr[0]
        
    for i in range(2, n+1):
        j = i-1 # as index in array is less than 1
        dp[i] = max(dp[i-1], # exclude ith element which is at i-1 index in arr
                    arr[j] + dp[i-2], # include ith@i-1 in arr, exclude i-1th @i-2 in arr, then find for i-2@dp
                    arr[j]+ arr[j-1] + dp[i-3]) # include at ith@i-1, i-1@i-2, exclude i-2th@i-3, find for dp 
       
    return dp[n]


arr = [1,2,3] # 5
n = len(arr)
print(recursive(arr, n-1))
print(dp_tabulation(arr, n))
print(dp_tabulation1(arr, n))