# you are given n friends and you need to find no of ways to 
# 1. either single or pair wise group of friends.
# f(n) = f(n-1) + (n-1)f(n-2)
# i am single and find ways to pair rest of student.
# i am makring with pair 2 to n then find pair for rest of student.
# 2 to n is n-1

def recursive(n):
    if n <=2:
        return n
    return recursive(n-1) + (n-1)*recursive(n-2)

dp = [0]*1000
def dp_recursive(n):
    if n<=2:
        dp[n] = n
        return n
    if dp[n]:
        return dp[n]
    dp[n] =  dp_recursive(n-1) + (n-1)*dp_recursive(n-2)
    return dp[n]

def dp_tab(n):
    dp = [0]*(n+1)
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n+1):
        dp[i] = dp[i-1] + (i-1)*dp[i-2]
    return dp[n]


n = 4
print(recursive(n))
print(dp_recursive(n))
print(dp_tab(n))