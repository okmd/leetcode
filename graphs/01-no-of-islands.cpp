// GFG solution for 8 directions
void crawl(int i, int j, int m, int n, vector<vector<char>>& grid) {
    if (i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != '1') return;
    grid[i][j] = '2';
    int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
    int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
    for (int k = 0; k < 8; k++) {
        crawl(i + dx[k], j + dy[k], m, n, grid);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int rows = grid.size();
    if (rows == 0) return cnt;
    int cols = grid[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                // in one go i.e dfs call it will make 2 all adjacent 1;s
                // if anyother 1 exits that means it is the next island
                cnt++;
                crawl(i, j, rows, cols, grid);
            }
        }
    }
    return cnt;
}