# def substring_with_size_three(s, k):
#     output = []
#     res = [s[i: j] for i in range(len(s)) for j in range(i + 1, len(s) + 1) if len(s[i:j]) == k]
#     a_set = set()
#     for strings in res:
#         print(strings)
#         if strings[0] != strings[1] != strings[2] and strings[0] != strings[2] != strings[1]:
#             output.append(strings)

#     print(len(output))


    

# substring_with_size_three('aababcabc', 3)


def minimize_maximize(nums):
    nums = sorted(nums)
    sum_of_nums = []
    start = 0
    end = len(nums)-1
    while start < end:
        sum_of_nums.append(nums[start]+nums[end])
        start += 1
        end -= 1
    return max(sum_of_nums)


# minimize_maximize([3,5,4,2,4,6])

# def rhombus_sum(grid):
#     rhombus_sums = []
#     for rows in range(len(grid)):
#         for columns in range(len(grid[0])):
#             rhombus_sums.append(grid[rows][columns])
#     for row in range(1, len(grid)-1):
#         for col in range(1, len(grid)-1):
#             r_sum = grid[row][col]
#     print(rhombus_sums)


# rhombus_sum([[1,2,3],[4,5,6],[7,8,9]])
from itertools import permutations

def xor_sum_arr(nums1, nums2):
    res = []
    nums_2_perms = list(permutations(nums2))
    for arrs in range(len(nums_2_perms)):
        sums = 0
        for i in range(len(nums1)):
            sums += nums1[i] ^ nums_2_perms[arrs][i]
        res.append(sums)
    
    return min(res)


xor_sum_arr([1, 2], [2, 3])

