bool canPlace(int grid[N][N], int row, int col, int val) {
    for (int i = 0; i < N; i++) {
        // check col
        if (grid[i][col] == val) return false;
        // check row
        if (grid[row][i] == val) return false;
        // check submatrix
        // row/3 => gives 0(0-2),1(3-5),2(6-8) for (1-9) and multiplying with 3 gives the actual index of submatrix
        // i/3 to change row and i%3 to change col
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    // if value is not present in either of row/col/submatrix
    // then it can be placed
    return true;
}

bool SolveSudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // this cell is not filled so requires ans
            if (!grid[i][j]) {
                // try to place each value 1-9
                for (int val = 1; val <= N; val++) {
                    if (canPlace(grid, i, j, val)) {
                        grid[i][j] = val;
                        // if found ans for current cell then place next empty cell
                        // by taking current value
                        if (SolveSudoku(grid)) return true;
                        // when return false then only backtrack
                        grid[i][j] = 0;
                    }
                }
                // if at this position any value between 1-9 cant be placed
                // then execution will come here therefore unable to place any value
                // hence earlier placements was not correct hence backtrack
                return false;
            }
        }
    }
    // when grid is complete, and no cell is empty
    // it will not enter into the code hence return true as it has found the ans already
    return true;
}
