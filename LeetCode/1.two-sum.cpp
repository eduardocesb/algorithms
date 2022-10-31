/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;

        for (int i = 0; i < nums.size(); i++)
        {
            if (index.count(target - nums[i]))
                return {index[target - nums[i]], i};

            index[nums[i]] = i;
        }
        
        return {};
    }
};
// @lc code=end

