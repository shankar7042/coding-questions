from typing import List


subsets_arr: List[List[int]] = []


def subsets1(arr: List[int], curr_subset: List[int] = [], pos: int = 0) -> None:
    if pos == len(arr):
        subsets_arr.append(curr_subset[::])
        return

    subsets1(arr, curr_subset, pos+1)
    curr_subset.append(arr[pos])
    subsets1(arr, curr_subset, pos+1)
    curr_subset.pop(-1)


def subset2(arr: List[int], curr_subset: List[int] = [], pos: int = 0) -> None:
    subsets_arr.append(curr_subset[::])
    for i in range(pos, len(arr)):
        curr_subset.append(arr[i])
        subset2(arr, curr_subset, i+1)
        curr_subset.pop()

# Using [1, 2, 3] as an example, the iterative process is like:

# Initially, one empty subset [[]]
# Adding 1 to []: [[], [1]];
# Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
# Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].


def subset_iterative(nums):
    powerset = [[]]
    for i in range(len(nums)):
        size = len(powerset)
        for j in range(size):
            powerset.append(powerset[j][::])
            powerset[-1].append(nums[i])
    return powerset

# Using [1, 2, 3] as an example, 1 appears once in every two consecutive subsets,
# 2 appears twice in every four consecutive subsets, and
# 3 appears four times in every eight subsets (initially all subsets are empty):

# [], [ ], [ ], [    ], [ ], [    ], [    ], [       ]
# [], [1], [ ], [1   ], [ ], [1   ], [    ], [1      ]
# [], [1], [2], [1, 2], [ ], [1   ], [2   ], [1, 2   ]
# [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]


def subset_bit_manipulation(nums):
    size = len(nums)
    pow_size = 1 << size
    powerset = [[] for _ in range(pow_size)]

    for i in range(pow_size):
        for j in range(size):
            if (i >> j) & 1:
                powerset[i].append(nums[j])
    return powerset


def subset_without_repitition(arr: List[int], curr_subset: List[int] = [], pos: int = 0) -> None:
    subsets_arr.append(curr_subset[::])
    for i in range(pos, len(arr)):
        if i > pos and arr[i] == arr[i-1]:
            continue
        curr_subset.append(arr[i])
        subset2(arr, curr_subset, i+1)
        curr_subset.pop()


permutations_arr: List[List[int]] = []


def permutations(arr: List[int], pos: int = 0) -> None:
    if pos == len(arr):
        permutations_arr.append(arr[::])
        return

    for i in range(pos, len(arr)):
        arr[i], arr[pos] = arr[pos], arr[i]
        permutations(arr, pos+1)
        arr[i], arr[pos] = arr[pos], arr[i]


print(subset_bit_manipulation([1, 2, 3]))
