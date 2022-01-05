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
    # For ABCD p will have n(5) elements as p0 to p4. Adim(p0, p1), Bdim(p1,p2)..
    # Create dp table of size n(5)
    # 1st row and 1st col not represent anything 10->nothing, 01->nothing.
    # Take either upper lower or triangular matrix.
    # [i][i] -> represent only single matrix. hence no multiplication.
    # 12-> AB, 13->ABC, 14->ABCD, 23->BC, 24->BCD, 34->CD, 44->D
    n = len(p)
    dp = [[maxsize]*(n) for _ in range(n)]
    # 0th row and col not used
    for i in range(1, n):
        dp[i][i] = 0
    # start multiplying the matrix from 2 till n-1 i.e AB, ABC , ABCD[2,3,4]
    for cl in range(2, n):
        # n-cl = number of cells in diagonal 1 above the previous diagonal.
        for i in range(n-cl):# cl=2, i=0,1,2 | cl=3, i=0,1 | cl=4, i=0
            # end point of the triangular matrix.
            j = cl+i # cl=2, j=2,3,4 | cl=3, j=3,4 | cl=4, j=4
            # always start with 1,x ans move diagonally downward.
            i += 1
            for k in range(i, j):# (1,4) = min((1,1)+(2,4)+x, (1,2)+(3,4), (1,3)+(4,4))
                dp[i][j]  = min(dp[i][j], dp[i][k] + dp[k+1][j] +p[i-1]*p[k]*p[j])
    return dp[1][n-1]


p = [4,2,3,1,3] # 4x2 2x3 3x1 1x3 ABCD
print(recursive(p, 1, len(p)-1))
print(memoization(p))
print(tabulation(p))

p = [1,2,3,4,5] # 1x2 2x3 3x4 4x5 ABCD
print(recursive(p, 1, len(p)-1))
print(memoization(p))
print(tabulation(p))