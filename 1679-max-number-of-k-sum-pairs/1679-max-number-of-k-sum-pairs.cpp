class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size()-1;
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        while(l < r){
            int cand = nums[l] + nums[r];
            
            if(cand < k){
                l++;        
            }else if(cand > k){
                r--;
            }else{
                l++;
                r--;
                res++;
            }
        }
        
        return res;
    }
};