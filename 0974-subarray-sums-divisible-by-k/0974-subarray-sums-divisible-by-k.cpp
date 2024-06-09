class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size() + 1, 0), remCount(k, 0);
        int divByK = 0;
        
        remCount[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            prefixSum[i+1] = (prefixSum[i] + nums[i]);
            
            if(prefixSum[i+1] < 0){
                prefixSum[i+1] += -k * floor(prefixSum[i+1] / (double)k);    
            }
            
            prefixSum[i+1] %= k;
            
            divByK += remCount[prefixSum[i+1]];
            remCount[prefixSum[i+1]]++;
        }
        
        return divByK;
    }
};