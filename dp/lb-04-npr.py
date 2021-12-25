# nPr = (n-1)Pr + r*(n-1)P(r-1)
# nCr = nPr/r!

def nPr(n, r):
    # O(n) and O(1)
    # n*(n-1)*..(n-r)!/(n-r)!
    ans = 1
    d = n-r
    while n != d:
        ans *= n
        n -= 1
    return ans


def dp_fact(n, r):
    # O(n) space n time.
    fact = [1]*(n+1)
    for i in range(2, n+1):
        fact[i] = i*fact[i-1]
    return fact[n]/fact[n-r]

def tabulation(n,r):
    dp =[[0]*(r+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(r+1):
            if i==0 and j==0:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j] + j*dp[i-1][j-1]
    return dp[n][r]


n = 3
r = 2
print(nPr(n, r))
print(dp_fact(n, r))
print(tabulation(n, r))
