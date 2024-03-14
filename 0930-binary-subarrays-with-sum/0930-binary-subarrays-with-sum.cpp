class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> zPos;
        int zeros = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                zPos.push_back(zeros + 1);
                zeros = 0;
            }else{
                zeros++;
            }
        }
        
        zPos.push_back(zeros + 1);
        
        int ans = 0;
        
        if(goal == 0){
            for(int i = 0; i < zPos.size(); i++){
                ans += zPos[i] * (zPos[i] - 1)/2;
            }
            return ans;
        }
        if(goal >= zPos.size()) return 0;
        
        for(int i = 0; i < zPos.size()-goal; i++){
            ans += zPos[i] * zPos[i + goal];
        }
        
        
        
        return ans;
    }
};