class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum(1, 0);
        
        for(int i = 0; i < nums.size(); i++)
            prefixSum.push_back(prefixSum[i] + nums[i]);
        
        for(int i = 0; i < nums.size(); i++)
            if(prefixSum[i] == prefixSum[nums.size()] - prefixSum[i+1])
                return i;
            
        return -1;
    }
};