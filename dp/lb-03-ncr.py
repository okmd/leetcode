# nPr = (n-1)Pr + r*(n-1)P(r-1)
# nCr = (n-1)C(r-1) + (n-1)C(r)
# comes from pascal's triangle
#           1       n=0
#          1 1      n=1
#         1 2 1     n=2
#       1  3 3  1   n=3
#      1 4  6  4  1 n=4
#   r=0  1  2  3  4

def basic(n,r):
    # O(n)
    r = min(n, r)
    res = 1
    for i in range(r):
        res *= (n-i)
        res /= (i+1)
    return res

def recursive(n,r):
    # O(2^n)
    if r>n:
        return 0
    if r==n or r==0:
        return 1
    return recursive(n-1,r-1) + recursive(n-1,r)

def tabulation(n, r):
    # O(n*r) and space O(n*r)
    dp = [[0]*(r+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(r+1):
            if j==0 or i==j:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    return dp[n][r]

def optimized_space(n, r):
    # O(n*r), O(r)
    dp = [0 for _ in range(r+1)]
    dp[0] = 1
    for i in range(1, n+1):
        j = min(i, r)
        while j:
            dp[j] +=  dp[j-1]
            j-=1
    return dp[r]

n = 3
r = 1
print(basic(n, r))
print(recursive(n,r))
print(tabulation(n, r))
print(optimized_space(n, r))
