/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
private:
    void removeInvalid(string &s, char open, char close)
    {
        int count = 0;

        for (auto &curr : s)
        {
            if (curr == open)
                count++;
            else if (curr != close)
                continue;
            else if (count == 0)
                curr = ' ';
            else
                count--;
        }
    }
public:
    string& minRemoveToMakeValid(string &s) {
        //Removing the extra closing parenthesis.
        removeInvalid(s, '(', ')');
        reverse(s.begin(), s.end());

        //Removing the extra opening parenthesis.
        removeInvalid(s, ')', '(');
        reverse(s.begin(), s.end());

        //Removing the extra spaces in the string
        int lastIndex = 0;
        for (auto curr : s)
            if (curr != ' ')
                s[lastIndex++] = curr;

        //Removing the extra chars remaing in the end
        s.resize(lastIndex);

        return s;
    }
};
// @lc code=end

