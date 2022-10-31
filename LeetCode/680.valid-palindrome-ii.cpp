/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
    bool checkIfIsAPalindrome(string &s, int l, int r)
    {
        while (l <= r)
            if (s[l] != s[r])
                return false;
            else
                l++, r--;

        return true;
    }

public:
    bool validPalindrome(string &s)
    {
        int l = 0, r = s.size() - 1;

        while (l <= r)
            if (s[l] != s[r])
                break;
            else    
                l++, r--;

        return checkIfIsAPalindrome(s, l + 1, r) || checkIfIsAPalindrome(s, l, r - 1);
    }
};
// @lc code=end
