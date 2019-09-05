//https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0LL;
        
        int N = nums.size();
        
        for(auto x : nums)
            sum += x;
        
        return (int)(((1LL * N * (N + 1)) / 2) - sum);
    }
};