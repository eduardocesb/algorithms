"""
Given a string s,
find the length of the longest substring without repeating characters.
"""


class Solution:

    def longest_substring(self, s):

        maxcount = 0
        index = 0
        if len(s) == 1:
            return 1

        for i, j in enumerate(s):
            if i == 0:
                current = s[0]
                continue

            if j in current:
                while current[0] != j:
                    index += 1
                    current = s[index:i+1]

                if current[0] == j:
                    index += 1

            current = s[index:i+1]

            if len(current) > maxcount:
                maxcount = len(current)

        return maxcount

sol = Solution()
print(sol.longest_substring('abcabcbb'))
print(sol.longest_substring(' '))
print(sol.longest_substring(''))
print(sol.longest_substring('pwwkew'))
print(sol.longest_substring('aab'))
print(sol.longest_substring('dvdf'))
print(sol.longest_substring('au'))
