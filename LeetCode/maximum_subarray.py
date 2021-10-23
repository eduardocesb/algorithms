"""
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum
and return its sum.
"""

class Solution:
    
    def maximum_subarray(self, nums):
        result_sum = []
        final_sum = 0
        temp_sum = 0
        for i in range(len(nums)):
            if nums[i] > 0:
                result_sum.append(nums[i])
            elif nums[i] < 0:
                total_leading = sum(nums[i:])
                if total_leading > 0:
                    result_sum.extend(nums[i:])
                    temp_sum = sum(result_sum)
                else:
                    temp_sum = sum(result_sum)
            if temp_sum > final_sum:
                final_sum = temp_sum
            temp_sum = 0
        
        return result_sum, final_sum

                    
sol = Solution()
print(sol.maximum_subarray([-2,1,-3,4,-1,2,1,-5,4]))