/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string &s) {
        int ans = 0, count = 0;

        for (auto &curr : s)
        {
            if (curr == '(') count++;
            else if (count) count--;
            else ans++;
        }

        return ans + count;
    }
};
// @lc code=end

