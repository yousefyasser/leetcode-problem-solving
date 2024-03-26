class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto x: points){
            pq.push({x[0], x[1]});
        }
        
        pair<int, int> prev = pq.top();
        pq.pop();
        int ans = 1;
        
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            
            if(prev.second < p.first){
                prev = p;
                ans++;
                continue;
            }
            
            prev = {max(prev.first, p.first), min(prev.second, p.second)};
        }
        
        return ans;
    }
};