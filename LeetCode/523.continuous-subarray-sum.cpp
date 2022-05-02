/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex = {{0, -1}};

        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (k != 0) sum %= k;

            if (firstIndex.count(sum) && i - firstIndex[sum] > 1)
                return true;

            firstIndex.insert({sum, i});
        }

        return false;
    }
};
// @lc code=end

