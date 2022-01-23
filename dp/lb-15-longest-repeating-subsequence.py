# Given two strings
# find the longest repeating subsequence matching in both the string
# Idea:
# if last element of string are matching then 1+lcs(n-1, m-1) only if current position is not same.
# as it is guranteed when char is matching and index is not same then it is repeating.
# if not matching then max(lcs(n,m-1), lcs(n-1, m))

def lcs_recursive(str1, str2, n, m):
    if n<0 or m<0:
        return 0
    if str1[n] == str2[m] and n!=m:
        return 1+lcs_recursive(str1, str2, n-1, m-1)
    return max(lcs_recursive(str1, str2, n-1, m), lcs_recursive(str1, str2, n, m-1))

def lcs_memoization(str1, str2):
    n = len(str1)
    m = len(str2)
    dp = [[0]*(m+1) for _ in range(n+1)]
    def helper(str1, str2, n, m):
        nonlocal dp
        if n<0 or m<0:
            return 0
        if str1[n] == str2[m] and n!=m:
            dp[n][m] =  1+helper(str1, str2, n-1, m-1)
            return dp[n][m] 
        dp[n][m] = max(helper(str1, str2, n-1, m), helper(str1, str2, n, m-1))
        return dp[n][m] 
    return helper(str1, str2, n-1, m-1)

def lcs_tabulation(str1, str2):
    n = len(str1)
    m = len(str2)
    dp = [[0]*(m+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif str1[i-1] == str2[j-1] and i!=j:
                dp[i][j] = 1+ dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])
                
    return dp[n][m]


str1 = "AABCDD"
str2 = str1
n = len(str1)
m = len(str2)
print(lcs_recursive(str1, str2, n-1, m-1))
print(lcs_memoization(str1, str2))
print(lcs_tabulation(str1, str2))
