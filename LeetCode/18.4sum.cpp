class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i+3<nums.size(); i++){
            for(int j=i+1; j+2<nums.size(); j++){
                // quirky optimization
                if((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                
                int k=j+1, l=nums.size()-1;
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                        k++;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        l--;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
                
                while(j+1<nums.size() && nums[j] == nums[j+1]) j++;
            }
            
            while(i+1<nums.size() && nums[i] == nums[i+1]) i++;
        }
        
        return result;
    }
};