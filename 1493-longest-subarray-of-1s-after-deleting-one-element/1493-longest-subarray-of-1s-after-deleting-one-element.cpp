class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int l = 0;
        int r = 0;
        
        for(; r < nums.size(); r++){
            if(!nums[r]) count++;
            if(count > 1) count -= nums[l++] ? 0 : 1;
        }
        return r-l-1;
    }
};