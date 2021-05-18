def coin_change(coins, target):
    n = len(coins)
    table = [[0 for _ in range(target + 1)] for _ in range(n + 1)]

    for i in range(n+1):
        table[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if coins[i-1] > j:
                table[i][j] = table[i-1][j]
            else:
                table[i][j] = table[i-1][j] + table[i][j-coins[i-1]]

    return table[-1][-1]


coins = [1, 2, 3]
target = 5
print(coin_change(coins, target))
