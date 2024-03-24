class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo = 0;
        for(int x: nums){
            xo ^= x;
        }
        
        return xo;
    }
};