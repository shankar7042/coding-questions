import sys
arr = [10, 20, 30, 40, 30]
n = len(arr)
t = [[-1 for _ in range(n+1)] for _ in range(n+1)]


def solve(arr, i, j):
    if i >= j:
        return 0
    mn = sys.maxsize
    for k in range(i, j):
        temp = solve(arr, i, k) + solve(arr, k + 1, j) + \
            arr[i-1] * arr[k] * arr[j]

        mn = min(mn, temp)

    return mn


def solve_memo(arr, i, j):
    if i >= j:
        return 0

    if t[i][j] != -1:
        return t[i][j]

    mn = sys.maxsize

    for k in range(i, j):
        temp = solve(arr, i, k) + solve(arr, k + 1, j) + \
            arr[i-1] * arr[k] * arr[j]

        mn = min(mn, temp)
    t[i][j] = mn
    return t[i][j]


def isPalindrome(s):
    return s == s[::-1]


def palindrome_partition(s, i, j):
    if i >= j:
        return 0

    if isPalindrome(s[i:j+1]):
        return 0
    mn = sys.maxsize
    for k in range(i, j):
        temp = palindrome_partition(
            s, i, k) + palindrome_partition(s, k+1, j) + 1
        mn = min(mn, temp)
    return mn


string = "ababbbabbababa"
print(palindrome_partition(string, 0, len(string)-1))
