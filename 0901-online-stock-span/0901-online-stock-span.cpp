class StockSpanner {
public:
    vector<pair<int, int>> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        int i = int(prices.size()) - 1;
        
        while(i >= 0 && prices[i].first <= price){
            res += prices[i].second;
            i -= prices[i].second;
        }
        
        prices.push_back({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */