/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size();

        while (left <= right)
        {
            int middle = (left + right) / 2;

            if ((middle == 0 || nums[middle - 1] < nums[middle]) && (middle == nums.size() - 1 || nums[middle] > nums[middle + 1]))
            {
                return middle;
            }
            else if ((middle == 0 || nums[middle - 1] < nums[middle]))
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return 0;
    }
};
// @lc code=end
