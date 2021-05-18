a = "abcdaf"
b = "acbcf"

# longest_common_subsequence


def lcs(a: str, b: str):
    m = len(a)
    n = len(b)

    table = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, n+1):
            if a[i-1] == b[j-1]:
                table[i][j] = 1 + table[i-1][j-1]
            else:
                table[i][j] = max(table[i-1][j], table[i][j-1])

    ans = ""
    x, y = m, n
    while x > 0 and y > 0:
        if a[x-1] == b[y-1]:
            ans += a[x-1]
            x -= 1
            y -= 1
        else:
            if table[x-1][j] > table[x][y-1]:
                x -= 1
            else:
                y -= 1
    return ans[::-1]


def supersequence(a: str, b: str):
    m = len(a)
    n = len(b)

    table = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(1, m+1):
        for j in range(1, n+1):
            if a[i-1] == b[j-1]:
                table[i][j] = 1 + table[i-1][j-1]
            else:
                table[i][j] = max(table[i-1][j], table[i][j-1])

    ans = ""
    x, y = m, n
    while x > 0 and y > 0:
        if a[x-1] == b[y-1]:
            ans += a[x-1]
            x -= 1
            y -= 1
        else:
            if table[x-1][j] > table[x][y-1]:
                ans += a[x-1]
                x -= 1
            else:
                ans += b[y-1]
                y -= 1

    while x > 0:
        ans += a[x-1]
        x -= 1

    while y > 0:
        ans += b[y-1]
        y -= 1

    return ans[::-1]


print(supersequence(a, b))
