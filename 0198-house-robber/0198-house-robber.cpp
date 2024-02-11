class Solution {
public:
    vector<int> dp;
    
    int rob(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) 
            dp.push_back(-1);
        
        return trial(0, false, nums);
    }
    
    int trial(int index, bool prev, vector<int>& nums){
        if(index >= nums.size()) 
            return 0;
        if(prev) 
            return trial(index+1, !prev, nums);
        if(dp[index] != -1) 
            return dp[index];
        
        int take = nums[index] + trial(index+1, true, nums);
        int leave = trial(index+1, false, nums);
        
        return dp[index] = max(take, leave);
    }
};