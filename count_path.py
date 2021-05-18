def count_path(start, end):
    if start == end:
        return 1
    if start > end:
        return 0

    count = 0
    for i in range(1, 7):
        count += count_path(start+i, end)
    return count


def count_path_maze(n, i, j):
    if i == n-1 and j == n-1:
        return 1
    if i >= n or j >= n:
        return 0

    return count_path_maze(n, i+1, j) + count_path_maze(n, i, j+1)


print(count_path_maze(3, 0, 0))
