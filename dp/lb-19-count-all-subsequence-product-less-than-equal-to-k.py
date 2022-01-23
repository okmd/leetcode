# given array of n numbers and k.
# you need to count all the subsequence having product <= k.

def dp_tabulation(arr, k):
    n = len(arr)
    dp = [[-1]*(k+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(k+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif arr[i-1] > j:
                dp[i][j] = dp[i-1][j] # do not include the current element is > the product required. it will always give product > required.
            else:
                dp[i][j] = 1 + dp[i-1][j] + dp[i-1][int(j/arr[i-1])]  # all subsequence including and not including.
                # 1 => current individual element
                # => not including hence product required is j and numbers of element till i-1
                # => including current element, hence use till i-1 element and new product required is j/c.element
                
    return dp[n][k]



arr = [1,5,4,9,8,16]
k = 24
print(dp_tabulation(arr, k))