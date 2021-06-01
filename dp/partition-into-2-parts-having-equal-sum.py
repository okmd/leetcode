# https://www.geeksforgeeks.org/partition-problem-dp-18/
# Given array and you need to find weather array can be split into two parts having equal sums
# Yo need to tell weather it is possible to split into to parts or not.
# if we split into two parts, 2x = sum it means sum is always even, therefore odd sum can to split into 2 equal halfs.
# problem is reduced to finding subset with sum=sum/2 i.e half of sum. if exits then possible else not
# Brute force by generating all the subset
def bruteForceHelper(arr, n):
    sm = sum(arr)
    if sm & 1:
        return False
    return bruteForce(arr, sm//2, n)


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
def topDownHelper(arr, n):
    sm = sum(arr)
    if sm & 1:
        return False
    return topDown(arr, sm//2, n)


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
def bottomUpHelper(arr, n):
    sm = sum(arr)
    if sm & 1:
        return False
    return bottomUp(arr, sm//2, n)


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


def print_ans(arr, ans):
    sm = sum(arr)
    if ans:
        print(
            f"Yes, {arr} can be split into two parts having sum {sm}/2 = {sm//2}.")
    else:
        print(
            f"No, {arr} can't be split into two parts having sum {sm}/2 = {sm//2}.")


if __name__ == "__main__":
    arrs = [[3, 34, 4, 12, 5, 2], [3, 28, 4, 12, 5, 4], [3, 1, 5, 9, 12]]
    for arr in arrs:
        n = len(arr)
        print_ans(arr, bruteForceHelper(arr, n))
        print_ans(arr, topDownHelper(arr, n))
        print_ans(arr, bottomUpHelper(arr, n))
