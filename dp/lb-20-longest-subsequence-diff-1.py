# You are given array of n numbers
# you need to count the subsequences having difference between adj element 1.

def dp_tabulation(arr):
    n = len(arr)
    dp = [1]*n
    for i in range(n):
        for j in range(i):
            if abs(arr[i] - arr[j]) == 1: # distance is exaclty 1
                dp[i]  = max(dp[i], 1 + dp[j])
    return max(dp)
    
    
    
# arr = [10, 9, 4, 5, 4, 8, 6] # 3
arr = [1,2,3,4,5] # 5
print(dp_tabulation(arr))