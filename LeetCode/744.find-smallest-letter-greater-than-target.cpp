/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = (int)letters.size() - 1, mid, ans = 0;

        while (l <= r)
        {
            mid = (l + r) / 2;
            if (letters[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1, ans = mid;
        }

        return letters[ans];
    }
};
// @lc code=end

