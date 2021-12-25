# given knapsack capacity to be filled W.
# gien number of items: N
# values and weights of each of the items
N = 3
W = 3
values = [1, 2, 3]
weights = [4, 5, 6]


def knps(N, W, values, weights):
    # create dp table for wights cols and items rows
    dp = [[0]*(W+1) for _ in range(N+1)]
    for i in range(N+1):
        for j in range(W+1):
            # if either capacity is 0 or item is 0 then value is 0
            if i == 0 or j == 0:
                dp[i][j] = 0
            # if weight of item is > current capacity then don;t include
            elif weights[i-1] > j:
                dp[i][j] = dp[i-1][j]
            # else find the max by including and not including the item.
            else:
                # when included -> value is added but weight is subtracted from cap.
                # when not included -> simply remove the item and find same cap ans.
                dp[i][j] = max(values[i-1] + dp[i-1]
                               [j-weights[i-1]], dp[i-1][j])

    # last row and col represent the ans
    return dp[N][W]


print(knps(N, W, values, weights))
