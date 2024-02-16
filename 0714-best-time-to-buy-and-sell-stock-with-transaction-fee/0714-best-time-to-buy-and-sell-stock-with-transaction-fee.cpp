class Solution {
public:
    vector<int> buy;
    vector<int> sell;
    
    int maxProfit(vector<int>& prices, int fee) {
        buy = vector<int>(prices.size(), -1);
        sell = vector<int>(prices.size(), -1);
        return dp(0, prices, fee, false);
    }
    
    int dp(int index, vector<int>& prices, int fee, bool bought){
        if(index == prices.size()) return 0;
        
        int take = 0;
        int leave = 0;
        
        if(bought){
            if(sell[index] != -1) return sell[index];
            
            take = prices[index] - fee + dp(index+1, prices, fee, false);
            leave = dp(index+1, prices, fee, true);
            return sell[index] = max(take, leave);
        }else{
            if(buy[index] != -1) return buy[index];
            
            take = -prices[index] + dp(index+1, prices, fee, true);
            leave = dp(index+1, prices, fee, false);
            return buy[index] = max(take, leave);
        }
    }
};