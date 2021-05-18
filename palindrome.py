def next_palin(num):
    num += 1
    while True:
        if str(num) == str(num)[::-1]:
            return num
        num += 1

def next_palin_again(num):
    num_arr = list(map(int, list(str(num))))
    
    # To check if all digits is 9 or not
    flag = True
    for x in num_arr:
        if x != 9:
            flag = False
    
    if flag:
        ans = '1' + '0'*(len(num_arr)-1) + '1'
        return int(ans)
    
    # If all digits is not equal to 9
    flag = True if len(num_arr) % 2 == 0 else False

    if flag: # Even length
        mid = [len(num_arr) // 2 - 1, len(num_arr) // 2 ]

        if num_arr[mid[0]] != 9:
            num_arr[mid[0]] += 1
            num_arr[mid[1]] += 1
        else:
            while num_arr[mid[0]] == 9:
                num_arr[mid[0]] = 0
                num_arr[mid[1]] = 0
                mid[0] -= 1
                mid[1] += 1
            num_arr[mid[0]] += 1
            num_arr[mid[1]] += 1
        ans = ''.join(list(map(str, num_arr)))
        return int(ans)
    else: # Odd length
        mid = len(num_arr) // 2
        if num_arr[mid] != 9:
            num_arr[mid] += 1
            ans = ''.join(list(map(str, num_arr)))
            return int(ans)
        else:
            num_arr[mid] = 0
            mid = [len(num_arr) // 2 - 1, len(num_arr) // 2 + 1]

            if num_arr[mid[0]] != 9:
                num_arr[mid[0]] += 1
                num_arr[mid[1]] += 1
            else:
                while num_arr[mid[0]] == 9:
                    num_arr[mid[0]] = 0
                    num_arr[mid[1]] = 0
                    mid[0] -= 1
                    mid[1] += 1
                num_arr[mid[0]] += 1
                num_arr[mid[1]] += 1
            ans = ''.join(list(map(str, num_arr)))
            return int(ans)


print(next_palin(12921))
print(next_palin_again(12921))