# Given n items
# profit of each itmes
# wt of each item
# capacity of bag
# maximize the profit to take the item in the bag.
def dp_memoization(profit, weight, W):
    n  = len(profit)
    dp = [[-1]*(W+1) for _ in range(n+1)]
    
    def helper(profit, weight, w, i):
        if i==0 or w==0:
            dp[i][w] = 0
            return 0
        
        if dp[i][w]!=-1:
            return dp[i][w]
        
        if weight[i-1]>w:
            dp[i][w] = helper(profit, weight, w, i-1)
            return dp[i][w]
            
        dp[i][w] = max(helper(profit, weight, w, i-1),  profit[i-1] + helper(profit, weight, w-weight[i-1], i))
        return dp[i][w]
    
    return helper(profit, weight, W, n)

def dp_tabulation(profit, weight, W):
    n = len(profit)
    dp = [[-1]*(W+1) for _ in range(n+1)]
    for i in range(n+1):
        for j in range(W+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif weight[i-1]>j:
                # exclude
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], profit[i-1] + dp[i][j-weight[i-1]])
                # exclude and include but same element can be used if included
    return dp[n][W]

profit = [1,1]
weight = [2,1]
W = 3
print(dp_memoization(profit, weight, W))
print(dp_tabulation(profit, weight, W))