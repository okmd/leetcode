# Given two strings s and t.
# You need to convert s to t using minimum operation.
# U can only use Insert/Delete/Replace operation.

def recursive(s, t, n, m):
    if n == 0:
        return m

    if m == 0:
        return n

    if s[n] == t[m]:
        return recursive(s, t, n-1, m-1)
    return 1+min(
        recursive(s, t, n, m-1),  # Insert
        recursive(s, t, n-1, m),  # Delete
        recursive(s, t, n-1, m-1)  # repalce
    )


def dp_recursive(s, t, n, m):
    if n == 0:
        dp[n][m] = m
        return m
    if m == 0:
        dp[n][m] = n
        return m
    if dp[n][m] != -1:
        dp[n][m]
    if s[n] == t[m]:
        dp[n][m] = dp_recursive(s, t, n-1, m-1)
        return dp[n][m]
    dp[n][m] = 1+min(
        dp_recursive(s, t, n, m-1),  # Insert
        dp_recursive(s, t, n-1, m),  # Delete
        dp_recursive(s, t, n-1, m-1)  # repalce
    )
    return dp[n][m]


def dp_tabulation(s, t):
    n = len(s)  # length of string s
    m = len(t)  # length of string m
    # create dp table including when one of the string is empty.
    dp = [[-1]*(m+1) for _ in range(n+1)]
    for i in range(n+1):  # loop over the char of string s
        for j in range(m+1):  # loop over the char of string t
            if i == 0:  # when there is no char in s then operations required = no. of chars in t
                dp[i][j] = j
            elif j == 0:  # similarly when t don;t hanve any chars.
                dp[i][j] = i
            elif s[i-1] == t[j-1]:  # as it will start from 1 and string s, and t are of index 0 hence use n-1, m-1 to check for equality
                # as char are same so dont need any operation and problem reduced to one char less
                dp[i][j] = dp[i-1][j-1]
            else:  # else char don;t match
                dp[i][j] = 1+min(dp[i][j-1], # insert: at the rhs of s string and reduce 1 char from each as last char match.
                                 dp[i-1][j], # delete: delete curr char in s and n reduce but m does not as no match
                                 dp[i-1][j-1]) #replace: replaced to match and hence proplem reduced.
    return dp[n][m]


s = "geek"
t = "gesek"
n = len(s)
m = len(t)
dp = [[-1]*(m+1) for _ in range(n+1)]

print(recursive(s, t, n-1, m-1))
print(dp_recursive(s, t, n-1, m-1))
print(dp_tabulation(s, t))
