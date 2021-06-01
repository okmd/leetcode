# https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
# Given array and sum value
# Yo need to tell weather it is possible to get sum from subset of array.

# Brute force by generating all the subset
def bruteForce(arr, sm, n):
    if sm == 0:
        return True
    if n == 0:
        return False
    if sm < arr[n-1]:
        return bruteForce(arr, sm, n-1)  # not include

    # not include, not include.
    return bruteForce(arr, sm, n-1) or bruteForce(arr, sm-arr[n-1], n-1)


# Recursion + table = top down dp
dp = [[0 for _ in range(100+1)] for _ in range(100+1)]
def topDown(arr, sm, n):
    if sm == 0:
        return True
    if n == 0:
        return False
    if dp[n][sm]:
        return dp[n][sm]
    if sm < arr[n-1]:
        dp[n][sm] = topDown(arr, sm, n-1)
        return dp[n][sm]

    dp[n][sm] = topDown(arr, sm, n-1) or topDown(arr, sm-arr[n-1], n-1)
    return dp[n][sm]

# Iteratoin = bottom up dp
def bottomUp(arr, sm, n):
    dp = [[0 for _ in range(sm+1)] for _ in range(n+1)]
    for i in range(sm+1):
        dp[0][i] = False
        
    for i in range(n+1):
        dp[i][0] = True
        
    for i in range(1, n+1):
        for j in range(1, sm+1):
            if j < arr[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]

    return dp[i][j]


def print_ans(arr, sm, ans):
    if ans:
        print(f"Yes, sum {sm} is possible in arr {arr}.")
    else:
        print(f"No, sum {sm} is not possible in arr {arr}.")


if __name__ == "__main__":
    arr = [3, 34, 4, 12, 5, 2]
    n = len(arr)
    for sm in [3,48,58, 59]:
        print_ans(arr, sm, bruteForce(arr, sm, n))
        print_ans(arr, sm, topDown(arr, sm, n))
        print_ans(arr, sm, bottomUp(arr, sm, n))
