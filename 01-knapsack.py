def printMatrix(matrix):
    for i in matrix:
        print(i)


def isSubsetSum_recur(arr, target, n) -> bool:
    if target == 0:
        return True
    if n == 0:
        return False

    if arr[n-1] > target:
        return isSubsetSum_recur(arr, target, n-1)
    else:
        return isSubsetSum_recur(arr, target, n-1) or isSubsetSum_recur(arr, target - arr[n-1], n-1)


def isSubsetSum_memo(arr, target, n):
    if target == 0:
        return True
    if n == 0:
        return False

    if dp[n][target] != -1:
        return dp[n][target]

    if arr[n-1] > target:
        dp[n][target] = isSubsetSum_memo(arr, target, n-1)
        return dp[n][target]
    else:
        dp[n][target] = isSubsetSum_memo(
            arr, target, n-1) or isSubsetSum_memo(arr, target-arr[n-1], n-1)
        return dp[n][target]


def isSubsetSum_dp(arr, target):
    n = len(arr)

    dp = [[None for _ in range(target + 1)] for _ in range(n+1)]

    for i in range(1, target + 1):
        dp[0][i] = False

    for i in range(n+1):
        dp[i][0] = True

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if arr[i-1] > j:  # j is our current sum here
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]
    return dp[-1][-1]


def equal_sum_partition(arr):
    target = sum(arr)

    # if sum is odd we can't make a partition having sum equals
    if target & 1:
        return False

    target //= 2
    n = len(arr)
    dp = [[None for _ in range(target + 1)] for _ in range(n+1)]

    for i in range(1, target + 1):
        dp[0][i] = False

    for i in range(n+1):
        dp[i][0] = True

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if arr[i-1] > j:  # j is our current sum here
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]

    return dp[-1][-1]


def countSubsetSum(arr, target):
    n = len(arr)

    dp = [[None for _ in range(target + 1)] for _ in range(n+1)]

    for i in range(1, target + 1):
        dp[0][i] = 0

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if arr[i-1] > j:  # j is our current sum here
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]

    return dp[-1][-1]


def minimumSubsetSumDiff(arr):
    target = sum(arr)
    n = len(arr)

    dp = [[None for _ in range(target + 1)] for _ in range(n+1)]

    for i in range(1, target + 1):
        dp[0][i] = False

    for i in range(n+1):
        dp[i][0] = True

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if arr[i-1] > j:  # j is our current sum here
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]]

    min_diff = 999999
    for i in range((target+1)//2):
        if dp[-1][i]:
            min_diff = min(min_diff, target - 2*i)
    return min_diff


def countSubsetSumDiff(arr, diff):
    target = (sum(arr) + diff)

    if target & 1:
        return 0

    target //= 2

    n = len(arr)
    dp = [[None for _ in range(target + 1)] for _ in range(n+1)]

    for i in range(1, target + 1):
        dp[0][i] = 0

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, target + 1):
            if arr[i-1] > j:  # j is our current sum here
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]
    printMatrix(dp)
    return dp[-1][-1]


def targetSum_dp(arr, target, n, curr_sum):
    if curr_sum == target:
        return 1
    if n == 0:
        return 0

    positive = targetSum_dp(arr, target, n-1, curr_sum + arr[n])
    negaives = targetSum_dp(arr, target, n-1, curr_sum - arr[n])

    return positive + negaives


def targetSum(arr, target):
    n = len(arr) - 1
    curr_sum = 0
    return targetSum_dp(arr, target, n, curr_sum)


arr = [0, 0, 0, 0, 0, 0, 0, 0, 1]
target = 1
n = len(arr)
dp = [[-1 for i in range(target + 1)] for j in range(n + 1)]
print(targetSum(arr, target))
