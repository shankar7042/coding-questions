
def binary_search_asc(arr, key):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = start + ((end-start) // 2)
        if arr[mid] == key:
            return mid
        elif arr[mid] > key:
            end = mid-1
        else:
            start = mid+1
    return -1


def binary_search_desc(arr, key):
    start = 0
    end = len(arr)-1
    while start <= end:
        mid = start + ((end-start) // 2)
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            end = mid-1
        else:
            start = mid+1
    return -1


def binary_search_order_not_known(arr, key):
    if len(arr) == 1 and arr[0] == key:
        return 0
    else:
        if arr[0] < arr[1]:
            return binary_search_asc(arr, key)
        else:
            return binary_search_desc(arr, key)


def first_occurence(arr, key):
    start = 0
    end = len(arr)-1
    ans = -1
    while start <= end:
        mid = start + ((end - start) // 2)
        if arr[mid] == key:
            ans = mid
            end = mid - 1
        elif arr[mid] > key:
            end = mid - 1
        else:
            start = mid + 1
    return ans


def last_occurence(arr, key):
    start = 0
    end = len(arr) - 1
    ans = -1
    while start <= end:
        mid = start + ((end - start)//2)
        if arr[mid] == key:
            ans = mid
            start = mid + 1
        elif arr[mid] > key:
            end = mid - 1
        else:
            start = mid + 1
    return ans


def count(arr, key):
    return last_occurence(arr, key) - first_occurence(arr, key) + 1

# this funtion can also be used as to find the min_index


def no_of_rotation(arr):
    # No roattions happend
    if arr[0] < arr[-1]:
        return 0
    N = len(arr)
    start = 0
    end = N-1
    while start <= end:
        if arr[start] <= arr[end]:
            return start

        mid = start + ((end-start)//2)
        next = (mid + 1) % N
        prev = (mid - 1 + N) % N
        if arr[mid] <= arr[next] and arr[mid] <= arr[prev]:
            return mid
        elif arr[mid] >= arr[start]:  # means left part is sorted we have to go to the right part
            start = mid + 1
        elif arr[mid] <= arr[end]:  # means right part is sorted we have to go to the left part
            end = mid - 1


def find_min_index(arr):
    start = 0
    end = len(arr)-1
    while start < end:
        mid = (start + end) // 2
        if arr[mid] > arr[end]:
            start = mid + 1
        else:
            end = mid
    return start


def serach_in_rotated_arr(arr, key):
    min_index = no_of_rotation(arr)
    ans = binary_search_asc(arr[:min_index], key)
    if ans != -1:
        return ans
    ans = binary_search_asc(arr[min_index:], key)
    if ans != -1:
        return ans + min_index
    return -1


def floor(arr, key):
    start = 0
    end = len(arr) - 1
    ans = -1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            ans = mid
            start = mid + 1
        else:
            end = mid - 1
    return ans


def ceil(arr, key):
    start = 0
    end = len(arr) - 1
    ans = -1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            start = mid + 1
        else:
            ans = mid
            end = mid - 1
    return ans


def min_diff(arr, key):
    start = 0
    end = len(arr) - 1
    ans = -1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == key:
            ans = mid
            break
        elif arr[mid] < key:
            ans = mid
            start = mid + 1
        else:
            end = mid - 1
    if arr[ans] == key:
        return 0
    else:
        if ans == len(arr) - 1:
            return abs(arr[ans] - key)
        else:
            return min(abs(arr[ans] - key), abs(arr[ans + 1] - key))


def peak_element(arr):
    if len(arr) == 1:
        return arr[0]
    if arr[0] >= arr[1]:
        return 0
    elif arr[-1] >= arr[-2]:
        return len(arr) - 1

    start = 1
    end = len(arr) - 2

    while start <= end:
        mid = (start + end) // 2

        if arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid+1]:
            return mid
        elif arr[mid + 1] >= arr[mid]:
            start = mid + 1
        elif arr[mid-1] >= arr[mid]:
            end = mid - 1

# 4^(1/2) = 2 and 2^(1/2) = 1.414


def mul(n, p):
    res = 1
    for _ in range(p):
        res *= n
    return res


def root(num, x):
    lo = 1
    hi = num
    eps = 1e-7
    while hi - lo > eps:
        mid = (hi+lo)/2
        if mul(mid, x) > num:
            hi = mid
        else:
            lo = mid
    return lo


print(round(root(144, 3), 5))
print(round(root(2, 3), 5))
