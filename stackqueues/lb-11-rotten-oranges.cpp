
// optimization
int orangesRotting(vector<vector<int>>& grid) {
    // if grid is empty i.e the no element in the grid
    if (grid.empty()) return 0;
    //
    int rows = grid.size();
    int cols = grid[0].size();
    int days = 0;
    int non_zeros = 0;
    int rotten_till_now = 0;
    queue<pair<int, int>> rotten;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 0) non_zeros++;
            // push the rotten oranges in queue.
            if (grid[i][j] == 2) rotten.push({i, j});
        }
    }
    // 4 directions, down, up, right, left
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!rotten.empty()) {
        int current_rotten_oranges = rotten.size();
        rotten_till_now += current_rotten_oranges;
        // add current size of queue as cost
        while (current_rotten_oranges--) {
            // get the co-ordinate of current rotten orange
            int x = rotten.front().first;
            int y = rotten.front().second;
            // remove current rotten orange
            rotten.pop();
            // for each direction
            for (int i = 0; i < 4; ++i) {
                // updated co-ordinate to rotten the orange
                int nx = x + dx[i];
                int ny = y + dy[i];
                // if not lies within the matrix
                if (nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != 1) continue;
                // if lies and fresh is present
                // rott it ans place into the queue
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        // if new fresh oranges are rotten
        // then one more cycle will be required to rott adjancet fresh oranges
        if (!rotten.empty()) days++;
    }
    // if all are rott then days to rott else -1 for can;t be rott
    // as 1 becomes 2 and added to queue hence all 2's + 1's should be euqal to non_zeors if all are rott else not possible
    return non_zeros == rotten_till_now ? days : -1;
}