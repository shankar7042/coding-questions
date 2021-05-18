def couting_sort(arr):
    max_ele = max(arr)
    n = len(arr)
    count = [0] * (max_ele+1)
    output = [0] * n

    for i in range(n):
        count[arr[i]] += 1

    for i in range(1, len(count)):
        count[i] += count[i-1]

    print(count)

    for i in range(n):
        output[count[arr[i]]-1] = arr[i]
        count[arr[i]] -= 1

    for i in range(n):
        arr[i] = output[i]


arr = [1, 4, 1, 2, 7, 5, 2]
print(arr)
couting_sort(arr)
print(arr)
