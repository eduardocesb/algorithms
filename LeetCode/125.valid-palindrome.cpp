/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;

        while (l <= r)
        {
            while (l <= r && !isalnum(s[l])) l++;
            while (l <= r && !isalnum(s[r])) r--;
            if (l > r) return true;

            if (tolower(s[l]) != tolower(s[r])) return false;
            l++, r--;
        }

        return true;
    }
};
// @lc code=end

