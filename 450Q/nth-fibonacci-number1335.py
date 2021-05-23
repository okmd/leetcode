# https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
n = int(input("Fib? "))

# O(2^n) time complexity.


def recursion(n):
    if n == 0 or n == 1:
        return n
    return recursion(n-1) + recursion(n-2)


# recursion+table
# overlapping subproblem reduced.
dp = [-1 for _ in range(n+1)]


def topDown(n):
    if n == 0 or n == 1:
        return n

    if dp[n] != -1:
        return dp[n]

    dp[n] = topDown(n-1) + topDown(n-2)
    return dp[n]

# tabulation with no rec, iterattion
# O(n) time complexity and space complexity.


def bottomUp(n):
    if n == 0 or n == 1:
        return n
    dp = [0 for _ in range(n+1)]
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]


print(f"Pure recursion: {recursion(n)}. ")
print(f"TopDown dp: {topDown(n)}. ")
print(f"BottomUp dp: {bottomUp(n)}. ")
