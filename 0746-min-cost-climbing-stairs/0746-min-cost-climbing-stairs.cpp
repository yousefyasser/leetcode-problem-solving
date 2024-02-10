class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        memo.push_back(0);
        memo.push_back(0);
        
        for(int i = 2; i < len; i++){
            int cand1 = memo[i-1] + cost[i-1];
            int cand2 = memo[i-2] + cost[i-2]; 
            memo.push_back(min(cand1, cand2));
        }
        
        return min(memo[len-1] + cost[len-1], memo[len-2] + cost[len-2]);
    }
};