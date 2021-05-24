# https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/
# https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
def get_input():
    arr = [2, 2, 3]
    sm = int(input("Enter sum for subset? "))
    return arr, sm


def show_output(arr, sm, out):
    print(f"{ 'Yes' if out else 'Not'} possible, sum={sm}, in array: {arr}")

# Method 1: brute force


def recursive(arr, sm, n):
    if sm == 0:
        return True
    if n == 0:
        return False
    if arr[n-1] > sm:
        return recursive(arr, sm, n-1)
    return recursive(arr, sm, n-1) or recursive(arr, sm-arr[n-1], n-1)


arr, sm = get_input()
show_output(arr, sm, recursive(arr, sm, len(arr)))

# Method 2: Top down dp/ recursion + table -> memoization
dp = [[False for _ in range(sm+1)] for _ in range(len(arr)+1)]
    
def topDownDp(arr, sm, n):
    # already calculated.
    if dp[n][sm]:
        return dp[n][sm]
    # sum 0 is always possible.
    if sm == 0:
        dp[n][sm] = True
    # no sum can be formed by none elements except 0 sum.
    elif n == 0:
        dp[n][sm] = False
    # exclude if value is more than required sum.
    elif arr[n-1]>sm:
        dp[n][sm] = topDownDp(arr, sm, n-1) 
    # otherwise get if, sum is possible with or without including the item.
    else:
        dp[n][sm] = topDownDp(arr, sm, n-1) or topDownDp(arr, sm-arr[n-1], n-1)
    return dp[n][sm]


show_output(arr, sm, topDownDp(arr, sm, len(arr)))

# Method 3: dp bottom up tabulation.
def bottomUp(arr, sm, n):
    dp = [[False for _ in range(sm+1)] for _ in range(len(arr)+1)]
    # sum=0 is possible for any no of elements
    for i in range(sm+1):
        dp[0][i] = False
    # when no of elements are 0, no sum can be formed except 0
    for i in range(n+1):
        dp[i][0] = True

    for i in range(1, n+1):
        for j in range(1, sm+1):
            if arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
    return dp[n][sm]


show_output(arr, sm, bottomUp(arr, sm, len(arr)))
