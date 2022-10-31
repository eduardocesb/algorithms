def combination_sum(arr, target):

    rem_dict = dict()
    result = []
    for num in arr:
        if target % num == 0:
            result.append([num] * (target // num))
        difference = abs(target - num)
        rem_dict[num] = difference
    
    count = 0
    for key, diff in rem_dict.items():
        for num in arr:
            if diff != 0:
                if max(num, diff) % min(num, diff) == 0:
                    new_list = [num] * (max(num, diff)//min(num, diff))
                    new_list.append(key)
                    if sum(new_list) == target:
                        if new_list not in result:

                            result.append(new_list)



    return result


print(combination_sum([2,3,6,7], 7))
