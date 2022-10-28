class Solution {
public:
    unordered_map<char, string> options = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    void backtracking(string &s, int i, string &digits, vector<string> &result){
        if(i == digits.size() && i > 0) result.push_back(s);
        else {
            for(char c: options[digits[i]]){
                s += c;
                backtracking(s, i+1, digits, result);
                s.pop_back();
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string s;
        backtracking(s, 0, digits, result);
        return result;
    }
};