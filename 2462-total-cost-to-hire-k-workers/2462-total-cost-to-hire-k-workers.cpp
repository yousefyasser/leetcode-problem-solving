class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int start = candidates, end = int(costs.size()) - 1 - candidates;
        
        for(int i = 0; i < start; i++){
            pq.push({costs[i], i});
        }
        for(int i = int(costs.size())-1; i > max(start-1, end); i--){
            pq.push({costs[i], i});
        }
        
        long long res = 0;
        while(k--){
            pair<int, int> cand = pq.top(); 
            res += cand.first;
            pq.pop();
            
            if(start <= end){
                int dis1 = abs(cand.second - start);
                int dis2 = abs(cand.second - end);
                
                if(dis1 <= dis2){
                    pq.push({costs[start], start++});
                }else{
                    pq.push({costs[end], end--});
                }
            }
        }
        return res;
    }
};