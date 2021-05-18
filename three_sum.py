def three_sum(arr, target):
    arr = sorted(arr)
    n = len(arr)
    for i in range(len(arr)-2):
        low = i + 1
        high = n - 1
        while low < high:
            total = arr[i] + arr[low] + arr[high]
            if total == target:
                return (True, [arr[i], arr[low], arr[high]])
            elif total < target:
                low += 1
            else:
                high -= 1
    return False


print(three_sum(arr=[12, 3, 6, 9, 34, 25], target=24))
