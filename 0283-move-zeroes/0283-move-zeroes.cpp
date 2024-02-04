class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool end = false;
    
        for(int i = 0; i < nums.size() && !end; i++){
            if(!nums[i]){
                end = true;
                
                for(int j = i+1; j < nums.size(); j++){
                    if(nums[j]){
                        end = false;
                        int tmp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = tmp;
                        break;
                    }
                }
            }
        }
    }
};