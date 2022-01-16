# given n length rod
# each cut of size either x,y,z
# count maximum such segment
import sys
minsize = -sys.maxsize
# recursion depth limit
def recursive(n,x,y,z):
    dp = [-1]*10005
    def helper(n,x,y,z):
        nonlocal dp
        if n==0:
            return 0
        if dp[n]!=-1:
            return dp[n]
        # cut rod of x lengths
        x_cut = helper(n-x,x,y,z) if n>=x else minsize
        y_cut = helper(n-y,x,y,z) if n>=y else minsize
        z_cut = helper(n-z,x,y,z) if n>=z else minsize
        dp[n] = 1 + max(x_cut, y_cut, z_cut)
        return dp[n]
    return helper(n,x,y,z)

#optimization
def max_segment(n,x,y,z):
    cuts = [x,y,z]
    m = len(cuts)
    dp = [[minsize]*(n+1) for _ in range(m+1)]
    for i in range(1, m+1):
        for j in range(n+1):
            # NOTE: for for no cut or i==0 not possible to cut hence -inf
            if j == 0:# when rod size is 0 and cut is of any length
                dp[i][j] = 0
            elif cuts[i-1]>j: # when cut length is more that rod length
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(1+dp[i][j-cuts[i-1]], dp[i-1][j])
                
    return dp[m][n] if (dp[m][n]>0) else 0
    


# input and execution
print(recursive(5,5,3,2), max_segment(5,5,3,2))#2
print(recursive(7,5,5,2), max_segment(7,5,5,2))#2
# print(recursive(4000,1,2,3), max_segment(4000,1,2,3))#4000
print(recursive(9999,94,20,244), max_segment(9999,94,20,244))#0