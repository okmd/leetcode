# Given array and difference
# find no of ways to split in array into two parts such that differece is same as given difference.
# s1 - s2 = diff
# s1 - (sum-s1) = diff
# 2s1 = diff + sum
# s1 = (sum+diff)/2
# if sum s1 exists then it is possible to divide into two parts with given diff.

# Now problem is reduced to count subsets having sum s.

def bottomUp(arr):
    n = len(arr)
    sm = sum(arr)
    dp = [[1 for _ in range(sm+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(sm+1):
            if j==0:
                dp[i][j]=1
            elif i==0:
                dp[i][j]=0
            elif j < arr[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]
    return dp[n][sm]
     
if __name__=="__main__":
    arr = [3,1,2,3]
    diff = 3
    print(f"Subsets with difference {diff} is {bottomUp(arr)}.")