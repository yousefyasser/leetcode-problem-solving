class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long sum = 0;
        map<int, int> rem;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            if(sum % k == 0 && i > 0){
                return true;
            }
            if(rem[sum % k] == 0){
                rem[sum % k] = i+1;        
            }else{
                if(i+1 - rem[sum % k] > 1){
                    return true;
                }
            }
        }
        
        return false;
    }
};