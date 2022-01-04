# Write a function to find the longest common prefix string amongst an array of strings.

# If there is no common prefix, return an empty string "".

class Solution:
    def longestCommonPrefix(self, strs) -> str:
        
        maxi = max(strs)
        mini = min(strs)
        
        print(mini)
        print(maxi)
        
        for i in range(len(mini)):
            
            if mini[i] != maxi[i]:
                return mini[:i]
            
            
        return mini


sol = Solution()
print(sol.longestCommonPrefix(["dr", "de", "den"]))