class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double cand = 0;
        
        for(int i = 0; i < k; i++){
            cand += nums[i];
        }
        
        double best = cand / k;
        
        for(int i = k; i < nums.size(); i++){
            cand += nums[i] - nums[i-k];
            best = max(best, cand / k);
        }
        
        return best;
    }
};