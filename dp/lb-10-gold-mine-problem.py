# given a matrix of gold coins,
# collect maximum coins by visiting the cell in top right(diagonal up), right, bottom right(diagonal down).
# your current posion is col 0 at any row
        
def get_dp(dp, r, c, n, m):
    if r<0 or r>=n or c<0 or c>=m:
        return 0
    return dp[r][c]


def tabulation(mat):
    n, m = len(mat),len(mat[0]) # row, col
    dp = [[0]*m for _ in range(n)]
    for c in range(m-1, -1, -1):
        for r in range(n-1, -1, -1):
            if c==m-1:
                dp[r][c] = mat[r][c]
            else:
                dp[r][c] = mat[r][c] + max(get_dp(dp, r-1, c+1, n, m), get_dp(dp, r, c+1, n, m), get_dp(dp, r+1, c+1, n, m))
                # diagonal right up, right, diagonal right down
    return max(map(lambda x:x[0], dp))
                
                
mat1 = [[1, 3, 3],
        [2, 1, 4],
        [0, 6, 4]]

mat2 = [[1,3,1,5],[2,2,4,1],[5,0,2,3],[0,6,1,2]]
mat3 = [[10,33,13,15], [22,21,4, 1], [5,0,2,3], [0, 6, 14, 2]]


print(tabulation(mat1)) #12
print(tabulation(mat2)) #16
print(tabulation(mat3)) #83