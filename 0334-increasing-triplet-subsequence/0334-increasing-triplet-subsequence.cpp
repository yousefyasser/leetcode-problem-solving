class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        int min2 = min;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= min){
                min = nums[i];
            }else{
                if(nums[i] <= min2){
                    min2 = nums[i];
                }else{
                    return true;
                }
            }
        }
        return false;
    }
};