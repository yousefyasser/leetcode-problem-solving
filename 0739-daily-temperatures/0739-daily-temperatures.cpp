class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> s;
        
        for(int i = 0; i < temperatures.size(); i++){
            while(!s.empty() && s.top().first < temperatures[i]){
                pair<int, int> p = s.top();
                s.pop();
                
                ans[p.second] = i - p.second;
            }
            
            s.push({temperatures[i], i});
        }
        
        return ans;
    }
};