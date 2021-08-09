# https://leetcode.com/problems/number-of-islands/

def visit_island(grid, x, y, r, c):
    if x < 0 or x >= r or y < 0 or y >= c or grid[x][y] != '1':
        return
    grid[x][y] = '2'
    visit_island(grid, x, y+1, r, c)
    visit_island(grid, x+1, y, r, c)
    visit_island(grid, x, y-1, r, c)
    visit_island(grid, x-1, y, r, c)


def count_islands(grid):
    rows = len(grid)
    if not rows:
        return
    cols = len(grid[0])
    islands = 0
    for x in range(rows):
        for y in range(cols):
            if grid[x][y] == '1':
                islands += 1
                visit_island(grid, x, y, rows, cols)
    return islands


if __name__ == "__main__":
    grid = [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"],
            ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
    print(f"There are {count_islands(grid)} islands.")
