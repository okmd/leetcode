# FIND min diff
# You are given an array of size n
# you need to divide the array into 2 parts such taht the difference between their sum is minimum.
# s1 + s2 = sum
# abs(s1 - s2) = diff = min
# when diff is 0(minimum) i.e s1 = s2 i.e divided into 2 eaual sum subset.
# i.e s1 = s2 = sum/2 <- least minimum value at this sum.
# when not 0 that means one will be more and one will be less.
# when s1 <= s2 and s1 <= sum/2; maximum possible value s2 can take is sum/2;
# Now find s1 <= sum/2 as diff = sum-2s1 = s2-s1 = sum-s1 - s1, diff will always +ve.
# diff will be minimum when s1 is less than sum/2.

# Method 1:
# Recursion Method

# Method 2:
# Recursion + memoization + topDown Dp

# Method 3:
# Iteration + tabulation + bottomUp Dp


def bottomUp(arr):
    n = len(arr)
    sm = sum(arr)
    dp = [[False for _ in range(sm+1)] for _ in range(n+1)]

    # no of elements
    for i in range(n+1):
        # requied sum from 1 to sm
        for j in range(sm+1):
            if j==0:
                dp[i][j] = True
            elif i==0:
                dp[i][j]=False
            # not including as the element is greather than required sum.
            elif arr[i-1] > j:
                dp[i][j] = dp[i-1][j]
            else:
                # Check by not including and including the element(arr[i-1])
                # when element is included then required sum is reduced by element value.
                # current element is denoted by i-1
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]

    # finding min diff subset
    min_diff = 100000
    for s1 in range(sm//2, 0, -1):
        s2 = sm - s1
        if min_diff > s2-s1 and dp[n][s1]:
            min_diff = s2-s1
            print(f"Sum of s1 is:{s1} and s2:{s2}.")

    return min_diff


def printAns(ans):
    print(f"Minimum difference is: {ans}.")


if __name__ == "__main__":
    arr = [1, 2, 34, 4]
    printAns(bottomUp(arr))
