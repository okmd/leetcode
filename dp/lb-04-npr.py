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


n = 3
r = 3
print(nPr(n, r))
print(dp_fact(n, r))
