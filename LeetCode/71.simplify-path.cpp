/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string &path) {
        vector<string> current_path;

        path += "/";

        string curr_dir = "";

        for (auto &curr : path)
        {
            if (curr == '/')
            {
                if (curr_dir == "" || curr_dir == "."){
                    curr_dir = "";
                    continue;
                }
                else if (curr_dir == ".." && !current_path.empty()) current_path.pop_back();
                else if(curr_dir != "..") current_path.push_back(curr_dir);

                curr_dir = "";
            }
            else
                curr_dir += curr;
        }

        string ans = "";

        for (auto &curr : current_path)
            ans += "/" + curr;

        if (ans == "") ans = "/";

        return ans;
    }
};
// @lc code=end

