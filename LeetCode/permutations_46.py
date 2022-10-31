"""
Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order.
"""
# Input: nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution:

    def permutations(self, arr):
        
        result = []
        for i in range(len(arr)):
            popped = arr.pop(i)
            for j in range(len(arr)):
                arr.insert(j, popped)
                result.append(arr)
                # print(result)
                arr.pop(j)

            arr.insert(i, popped)

        
        return result


sol = Solution()
print(sol.permutations([1, 2, 3]))                