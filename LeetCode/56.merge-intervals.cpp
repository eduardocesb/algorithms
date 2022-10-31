/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
/*
Time Complexity: O(N * Log N)
Space Complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>>& merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int lastIndex = 0;

        for (auto curr : intervals)
            if (intervals[lastIndex][1] < curr[0])
                intervals[++lastIndex] = curr;
            else
                intervals[lastIndex][1] = max(intervals[lastIndex][1], curr[1]);

        intervals.resize(lastIndex + 1);

        return intervals;
    }
};
// @lc code=end

