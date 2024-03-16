class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int res = 0;
        map<int, int> mp;
        mp[0] = -1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) count++;
            else count--;
            
            if(mp.find(count) == mp.end()){
                mp[count] = i;
            }else{
                res = max(res, i - mp[count]);
            }
        }
        
        return res;
    }
};