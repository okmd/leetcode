// distance = min(abs(i1-i2) + abs(j1-j2))

// if out of matrix or not
bool is_valid(int m, int n, int i, int j) {
    return (i >= 0 and i < m and j >= 0 and j < n);
}
// DFS approch
vector<vector<int>> nearest(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    // copy to make same dimension.
    vector<vector<int>> ans = grid;
    // make a Q to store all the 1;s initially so that it can start finding distance
    // to nearest zeros
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if cell is one then distance would be 0 as itself is 1.
            if (grid[i][j] == 1) {
                // min distance would be 0
                ans[i][j] = 0;
                // push the co-ordinate to Q.
                q.push({i, j});
            } else {
                // make the INF as min distance to this node from anynode
                ans[i][j] = INT_MAX - 1;
            }
        }
    }
    // while each cell distance is calculated.
    while (q.size()) {
        // current cell with 1(grid) or non-zero distance(ans)
        int current_x = q.front().first;
        int current_y = q.front().second;
        // pop this element as distance from this node is already computed
        q.pop();
        // 4 neighbouring directions
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        // for each direction
        for (int i = 0; i < 4; i++) {
            // neighbour's location
            int neigh_x = current_x + dx[i];
            int neigh_y = current_y + dy[i];
            // if valid i.e not out of matrix
            if (is_valid(m, n, neigh_x, neigh_y)) {
                // current distance of current cell and neighbous cell.
                int neigh_dist = ans[neigh_x][neigh_y];
                int curr_dist = ans[current_x][current_y];
                // if less distance is possible then update
                if (neigh_dist > curr_dist + 1) {
                    // push the cell with updated distance as this may lead to reduce
                    // distance of some other cell.
                    q.push({neigh_x, neigh_y});
                    // now update the reduced distance.
                    ans[neigh_x][neigh_y] = curr_dist + 1;
                }
            }
        }
    }
    // all cell with min distance from neighouring 1.
    return ans;
}