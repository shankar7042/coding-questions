grid = [
    [1, 1, 0, 0, 1],
    [1, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 1],
    [1, 1, 0, 1, 0]
]


def print_grid(grid):
    for row in grid:
        print(row)


def can_move(row, col, grid, visited):
    if row >= 0 and row < len(grid) \
            and col >= 0 and col < len(grid[0]) \
            and grid[row][col] == 1 and (not visited[row][col]):

        return True
    return False


def dfs(row, col, grid, count, visited):
    visited[row][col] = True
    count = 1
    for i in range(row-1, row+2):
        for j in range(col-1, col+2):
            if i != row or j != col:
                if can_move(i, j, grid, visited):
                    count += dfs(i, j, grid, count, visited)
    return count


def find_max_area(grid):
    visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
    max_area = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1 and (not visited[row][col]):
                max_area = max(max_area, dfs(row, col, grid, 0, visited))
    return max_area


print(find_max_area(grid))
