"""
Given n pairs of parentheses, write a function to generate 
all combinations of well-formed parentheses.
"""

class Solution:

    def generate_parenthesis(self, n):

        result = []
        text_result = ""
        for num in range(1, n+1):
            text_result = "(" * num + ")" * num
            result.append(text_result)
            print(text_result)


        return result


sol = Solution()
print(sol.generate_parenthesis(3))