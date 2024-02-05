class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix[i] contains the product from nums[0] to nums[i]
        // suffix[i] contains the product from nums[nums.size()-1] downto nums[i]
        vector<int> res, prefix, suffix;
        int len = nums.size();
        
        prefix.push_back(nums[0]);
        suffix.push_back(nums[len-1]);
        
        for(int i = 1; i < len-1; i++){
            prefix.push_back(prefix[i-1]*nums[i]);
            suffix.push_back(suffix[i-1]*nums[len-i-1]);
        }
        
        res.push_back(suffix[suffix.size()-1]);
        for(int i = 0; i < len-2; i++){
            int prod = prefix[i] * suffix[suffix.size()-i-2];
            res.push_back(prod);
        }
        res.push_back(prefix[prefix.size()-1]);
        
        return res;
    }
};