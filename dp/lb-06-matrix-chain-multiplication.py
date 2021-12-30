maxsize = 10**8

def recursive(p, i, j):
    if i==j:
        return 0
    res = maxsize
    for k in range(i,j):
        res = min(res, recursive(p,i, k) + recursive(p,k+1,j) + p[i-1]*p[k]*p[j])
    return res


def memoization(p):
    n = 10
    dp = [[maxsize]*n for _ in range(n)]

    def helper(p, i, j):
        # if there is only one matrix hence no matrix multiplication
        if i==j:
            return 0
        # return the precalculated result for overlapping subproblem.
        if dp[i][j] != maxsize:
            return dp[i][j]

        for k in range(i, j):
            dp[i][j] = min(dp[i][j], helper(p,i, k) + helper(p,k+1,j) + p[i-1]*p[k]*p[j])
        
        return dp[i][j]

    return helper(p, 1, len(p)-1)



def tabulation(p):
    n = len(p)
    dp = [[maxsize]*(n) for _ in range(n)]
    # 0th row and col not used
    for i in range(1, n):
        dp[i][i] = 0

    for cl in range(2, n):
        for i in range(1, n-cl + 1):
            j = cl+i-1
            for k in range(i, j):
                dp[i][j]  = min(dp[i][j], dp[i][k] + dp[k+1][j] +p[i-1]*p[k]*p[j])
    return dp[1][n-1]


p = [4,2,3,1,3] # 1x2 2x3 3x4 ABC
print(recursive(p, 1, len(p)-1))
print(memoization(p))
print(tabulation(p))

p = [1,2,3,4,5] # 1x2 2x3 3x4 ABC
print(recursive(p, 1, len(p)-1))
print(memoization(p))
print(tabulation(p))