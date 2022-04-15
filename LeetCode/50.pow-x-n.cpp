/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0 && n < 0)
        {
            assert(false);
        }

        double ans = 1.0;

        if (n == INT_MIN)
        {
            x *= x;
            n /= 2;
        }

        bool isNegative = n < 0;

        if (isNegative) 
        {
            n = -n;
        }

        while (n > 0)
        {
            if (n & 1) ans *= x;
            x *= x;
            n /= 2;
        }

        if (isNegative)
        {
            ans = 1.0 / ans;
        }
        
        return ans;
    }
};
// @lc code=end

