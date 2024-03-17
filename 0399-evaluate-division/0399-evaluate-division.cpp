class Solution {
public:
    map<string, vector<pair<string, double>>> adj;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        set<string> s;
        
        for(int i = 0; i < equations.size(); i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            s.insert(equations[i][0]);            
            s.insert(equations[i][1]);
        }
        
        vector<double> res;
        map<string, bool> vis;
        
        for(auto p: queries){
            if(!s.count(p[0]) || !s.count(p[1])){
                res.push_back(-1);
                continue;
            }
            
            vis.clear();
            
            double ans = dfs(p[0], p[1], vis);
            res.push_back(ans < 0 ? -1 : ans);
        }
        
        return res;
    }
    
    double dfs(string start, string target, map<string, bool>& vis){
        if(start == target) return 1.0;
        vis[start] = true;
        
        double res = -1;
        
        for(auto x: adj[start]){
            if(!vis[x.first]){
                double cand = dfs(x.first, target, vis);
                res = max(res, x.second * cand);
            }
        }
        
        return res;
    }
};