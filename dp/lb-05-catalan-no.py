# Cn = C0Cn-1 + C1Cn-2 + .. + Cn-1C0, C0=1
# Cn+1 = C0Cn + C1Cn-1 + .. + CnC0, C0=1
# Cn+1 = sum(CiCi-1) n>=0, from i=1 to n.
# Cn = 2nCn/(n+1) = 2n!/(n+1)n!
# T(n) = sum(T(i)*T(n-i-1)) n>=1, from i=0 to n-1

# Application of catalan no
# 1. No. Of BSTs        -> Cn
# 2. Unlabelled Trees
# 3. N paranthesis
# 4. Dyck Words
# 5. Mountain Ranges
# 6. Path on gird withoud crossing diagonal
# 7. Disjoin Cords
# 8. Convex Polygon     -> Cn-2
# 9. Catalan Triangulation
# 10. Matrix chain multiplication -> Cn-1, (multiplication of n matrix = n-1th cat no.)

def nCr(n,r):
    # O(n)
    r = min(n, r)
    res = 1
    for i in range(r):
        res *= (n-i)
        res /= (i+1)
    return res

def by_nCr(n):
    ans = nCr(2*n, n)
    return ans//(n+1)

def recursive(n):
    if n<=1:
        return 1
    res = 0
    for i in range(n):
        res += recursive(i)*recursive(n-i-1)
    return res

def by_dp(n):
    if n==0 or n==1:
        return 1
    dp = [0]*(n+1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n+1):
        for j in range(i):
            dp[i]+=dp[j]*dp[i-j-1] # C2 = C0C1 + C1C0
    return dp[n]





n = 5
print(by_nCr(n))
print(recursive(n))
print(by_dp(n))