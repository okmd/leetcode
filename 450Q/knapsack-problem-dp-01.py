# https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
# Problem: Iven set of items with weight and profit, and a capacity weight to place the items.
# you are require to place the items in the bag so that profit is maximize,

# Method 1:
# Recursion by brute-force algo.

def knapsack01(weights, profits, W, n):
    if n == 0 or W == 0:
        return 0
    if weights[n-1] > W:
        return knapsack01(weights, profits, W, n-1)
    else:
        return max(knapsack01(weights, profits, W, n-1), profits[n-1] + knapsack01(weights, profits, W-weights[n-1], n-1))


profits = [60, 100, 120]
weights = [10, 20, 30]
W = 50
n = len(profits)
print(knapsack01(weights, profits, W, n))

# Method 2 Dp
# Top down -> Memoization -> first solve large problem.
# Bottom up -> Tabulation -> first solve small problem.
# Tabulation, Bottom-up dp, no recursion


def knapsack01BottomUp(weights, profits, W, n):
    dp = [[0 for _ in range(W+1)] for _ in range(n+1)]
    for i in range(n+1):
        for w in range(W+1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i-1] > w:
                dp[i][w] = dp[i-1][w]
            else:
                dp[i][w] = max(dp[i-1][w], profits[i-1] +
                               dp[i-1][w-weights[i-1]])
    return dp[n][W]


print(knapsack01BottomUp(weights, profits, W, n))

# Method 3: Top down, with recursion
dp = [[0 for _ in range(W+1)] for _ in range(n+1)]


def knapsack01TopDown(weights, profits, W, n):
    if W == 0 or n == 0:
        dp[n][W] = 0
    elif weights[n-1] > W:
        dp[n][W] = knapsack01TopDown(weights, profits, W, n-1)
    else:
        dp[n][W] = max(knapsack01TopDown(weights, profits, W, n-1), profits[n-1] +
                       knapsack01TopDown(weights, profits, W-weights[n-1], n-1))
    return dp[n][W]


print(knapsack01TopDown(weights, profits, W, n))
