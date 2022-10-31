/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
/*
Time Complexity: O(N + (K * log N)), where N is the number of weights and K is the number os queries
Space Complexity: O(N)
*/
class Solution {
private:
    vector<int> prefixProbability;
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++)
        {
            int curr = w[i];

            if (i) curr += prefixProbability[i - 1];

            prefixProbability.push_back(curr);
        }
    }
    
    int pickIndex() {
        if (prefixProbability.empty())
            assert(false);

        int numberToFind = (rand() % prefixProbability.back()) + 1;

        return lower_bound(prefixProbability.begin(), prefixProbability.end(), numberToFind) - prefixProbability.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

