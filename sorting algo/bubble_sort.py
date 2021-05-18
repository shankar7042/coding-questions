def bubble_sort(arr):
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


arr = [10, 6, 3, 8, 9, 5]
print(arr)
bubble_sort(arr)
print(arr)
