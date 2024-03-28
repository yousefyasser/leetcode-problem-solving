class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(auto x: intervals){
            pq.push(x);
        }
        
        vector<int> prev = pq.top();
        pq.pop();
        int res = 0;
        
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            
            if(v[0] >= prev[0] && v[0] < prev[1]){
                res++;
                if(prev[1] > v[1]){
                    prev = v;
                }
            }else{
                prev = v;
            }
        }
        
        return res;
    }
};