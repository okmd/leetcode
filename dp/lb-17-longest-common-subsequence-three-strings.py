# You are given 3 strings you need to find lcs of them
# same as lcs of 2 string
def dp_tabulation(s1, s2, s3, l, m, n):
    dp = [[[0]*(l+1) for _ in range(m+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            for k in range(l+1):
                if i==0 or j==0 or k==0:
                    dp[i][j][k] = 0
                elif s3[i-1] == s2[j-1] == s1[k-1]:
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1]
                else:
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])
    
    return dp[n][m][l] 
    
    
s1 = "geeks"
s2= "geeksfor"
s3 = "geeksforgeeks"
l = len(s1)
m = len(s2)
n = len(s3)
print(dp_tabulation(s1, s2, s3, l, m, n)) #5