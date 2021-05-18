def counting_sort(arr, exp):
    pass


def radix_sort(arr):
    max1 = max(arr)
    exp = 1
    while max1 / exp > 0:
        counting_sort(arr, exp)
        exp *= 10


arr = [170, 45, 75, 90, 802, 24, 2, 66]
print(arr)
radix_sort(arr)
print(arr)
