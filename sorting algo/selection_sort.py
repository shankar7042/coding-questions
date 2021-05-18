def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min_ind = i
        for j in range(i+1, n):
            if arr[min_ind] > arr[j]:
                min_ind = j
        arr[i], arr[min_ind] = arr[min_ind], arr[i]


arr = [10, 6, 3, 8, 9, 5]
print(arr)
selection_sort(arr)
print(arr)
