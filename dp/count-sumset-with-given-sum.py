# https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
# Given array and sum value
# Yo need to tell how many subsets are possible in array having sum as given sum.

# Brute force by generating all the subset
def bruteForce(arr, sm, n):
    if sm == 0:
        return 1
    if n == 0:
        return 0
    if sm < arr[n-1]:
        return bruteForce(arr, sm, n-1)  # not include

    # not include, not include.
    return bruteForce(arr, sm, n-1) + bruteForce(arr, sm-arr[n-1], n-1)


# Recursion + table = top down dp
dp = [[0 for _ in range(100+1)] for _ in range(100+1)]
def topDown(arr, sm, n):
    if sm == 0:
        return 1
    if n == 0:
        return 0
    if dp[n][sm]:
        return dp[n][sm]
    if sm < arr[n-1]:
        dp[n][sm] = topDown(arr, sm, n-1)
        return dp[n][sm]

    dp[n][sm] = topDown(arr, sm, n-1) + topDown(arr, sm-arr[n-1], n-1)
    return dp[n][sm]

# Iteratoin = bottom up dp
def bottomUp(arr, sm, n):
    dp = [[0 for _ in range(sm+1)] for _ in range(n+1)]
    for i in range(sm+1):
        dp[0][i] = 0
        
    for i in range(n+1):
        dp[i][0] = 1
        
    for i in range(1, n+1):
        for j in range(1, sm+1):
            if j < arr[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]

    return dp[i][j]


def print_ans(arr, sm, ans):
    if ans:
        print(f"Yes, {ans} subarrys of sum {sm} is possible in arr {arr}.")
    else:
        print(f"No,  subarray of sum {sm} is not possible in arr {arr}.")


if __name__ == "__main__":
    arr = [1, 2, 3, 3]
    n = len(arr)
    for sm in [6, 5]:
        print_ans(arr, sm, bruteForce(arr, sm, n))
        print_ans(arr, sm, topDown(arr, sm, n))
        print_ans(arr, sm, bottomUp(arr, sm, n))
