# Given two assembly lines
# Given n nodes per line.
# Each node need a service time.
# Each line requires some entry and exit time.
# passing from one node two other don;t require extra time in same line
# but requires in other line to move diagonally rightward

def tabulation_min_time(nt, lct, et, xt):
    n = len(nt[0])
    dp = [[0]*n for _ in range(2)]
    # start from right
    for j in range(n-1, -1, -1):
        for i in range(2):
            if j==n-1:
                dp[i][j] = nt[i][j] + xt[i]
            else:
                dp[i][j] = nt[i][j] + min(dp[i][j+1], lct[i][j+1] + dp[(i+1)%2][j+1]) # change the line by taking mod
                
    # add entry time
    for i in range(2):
        dp[i][0] += et[i]
        
    return min(map(lambda x:x[0], dp))

# NOTE: further space can be optimized using the only two variable dp[0-1]
                
            


# inputs and running the code
node_time = [[4,5,3,2], [2,10,1,4]]
line_change_time = [[0,7,4,5], [0,9,2,8]]
exit_time = [18,7]
entry_time = [10,12]

print(tabulation_min_time(node_time, line_change_time, entry_time, exit_time))