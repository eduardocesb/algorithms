//https://leetcode.com/problems/can-make-palindrome-from-substring/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int N = s.length();
        
        int freq[26][N];
        
        //precalc
        for(int i = 0; i < N; i++)
            for(int j = 0; j < 26; j++)
                freq[j][i] = (j == s[i] - 'a') + (i ? freq[j][i - 1] : 0);
        
        vector<bool> r;
        
        int Q = queries.size();
        
        for(int i = 0; i < Q; i++)
        {
            int X = 0;
            
            for(int j = 0; j < 26; j++)
                X += (freq[j][queries[i][1]] - (queries[i][0] ? freq[j][queries[i][0] - 1] : 0)) & 1;
            
            
            r.push_back((X / 2) <= queries[i][2]);
        }
        
        return r;
        
    }
};