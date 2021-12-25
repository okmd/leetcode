# Note: given denominations and money to create change using given denominations.
# Problem 1: count possible number of ways to coin change.
def count_change(coins, n):
    count = 0

    def helper(coins, n, i):
        # nonlocal to bound the previous enclosing variable.
        nonlocal count
        if i >= len(coins) or n < 0:
            return
        if n == 0:
            count += 1
            return
        helper(coins, n-coins[i], i)
        helper(coins, n, i+1)

    helper(coins, n, 0)
    return count

# It will give TLE so apply optimization
# tabulation method


def tabulation(coins, n):
    m = len(coins)
    dp = [[-1]*(n+1) for _ in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            # it is always possible to create amount 0, not include anything.
            if i == 0 and j == 0:
                dp[i][j] = 1
            # no coins, but j amount is to be found=> no ways
            elif i == 0:
                dp[i][j] = 0
            # i coins, but 0 amount is to be formed always i.e 1.
            elif j == 0:
                dp[i][j] = 1
            # do not include the current coin as the coin value > required amount
            elif coins[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                # sum of ways by including and non including the current coin.
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]
    return dp[m][n]


# Extension of this problem is count minimum number of coins required to change n.
def min_coin_required(coins, n):
    maxint = 10**8
    m = len(coins)
    dp = [[maxint]*(n+1) for _ in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            # no coins, but j amount is to be found=> no ways
            if i == 0:
                dp[i][j] = maxint
            # i coins, but 0 amount is to be formed always i.e 1.
            elif j == 0:
                dp[i][j] = 0
            # do not include the current coin as the coin value > required amount
            elif coins[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                # sum of ways by including and non including the current coin.
                dp[i][j] = min(1+dp[i][j-coins[i-1]],  dp[i-1][j])

    return -1 if dp[m][n] == maxint else dp[m][n]


n = 4
coins = [1, 2, 5]
print(count_change(coins, n))
print(tabulation(coins, n))
print(min_coin_required(coins, n))
