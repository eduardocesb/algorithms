/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        int ans = 0, sum = 0;
        
        freq[0] = 1;
        
        for (auto &curr : nums)
        {
            sum += curr;
            
            ans += freq[sum - k];

            freq[sum]++;
        }
        
        return ans;
    }
};
// @lc code=end

