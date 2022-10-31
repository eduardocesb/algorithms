/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
public:
    string& customSortString(string &order, string &s) {
        int pos[26];

        for (int i = 0; i < order.size(); i++)
            pos[order[i] - 'a'] = i + 1;

        sort(s.begin(), s.end(), [&](char a, char b) 
        {
            return pos[a - 'a'] < pos[b - 'a'];
        });

        return s;
    }
};
// @lc code=end

