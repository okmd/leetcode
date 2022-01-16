# LEETCODE PREMIUM
# You are given n fence and k colors.
# You need to paint the fence such that no more than 2 adjacent fence are of same color.

# When N=1 i.e only once fence and k color
## it can be colored by anyone of the k color so = k possibilities

# when N=2, two fence and k color
## CASE1: when both fence are colored by same color = k*1 e.g rr, gg, bb when k=rgb, you must choose the previous color.
## CASE2: when both are of different color = k*(k-1) i.e r|gb, g|rb, b|rg

# when N=3
## case 1: when previous both were of same color, 3rd fence can;t be of same color as previous hence prevSame*(k-1). e.g rr|r
## case 2: when previous both are of different color, 3rd color can be any one of k color hence prevDiff*k. e.g rg|rgb, rb|rgb, gb|rgb, gr|rgb, br|rgb, bg|rgb
### Same = PrevDiff*1 as only one choice to select same color.
### Diff = PrevSame*(k-1) + PrevDiff*(k-1)

# Now generalize:
# Total(i) = Same(Si) + diffrence(Di)
# Si = Di-1
# Di = Si-1 * (k-1) + Di-1 *(k-1) = (k-1)[Si-1 + Di-1]  = (k-1)*Ti-1
# Ti = Si + Di =  Di-1 + (k-1)Ti-1
# Ti = (k-1)*Ti-2 + (k-1)Ti-1
# Ti = (k-1)*(Ti-1 + T-2) # Dp relation

def tabulation(n, k):
    dp = [0]*(n+1)
    dp[0] = k   # when N=1
    dp[1] = k*k # as k*1 + k*(k-1) for N=2
    for i in range(2,n):
        dp[i] = (k-1)*(dp[i-1] + dp[i-2])%1000000007
        
    return dp[n-1]

def space_optimized(n, k):
    if n==1:
        return k
    if n==2:
        return k*k
    
    pre_prev = k
    prev = k*k
    
    for _ in range(2, n):
        temp = prev
        prev = (k-1)*(prev + pre_prev)%1000000007
        pre_prev = temp
    
    return prev
    
    

k=4
for i in range(1,10):
    print(tabulation(i,k), space_optimized(i,k))