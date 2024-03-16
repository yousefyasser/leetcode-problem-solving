class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        
        for(auto& x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }
        
        vector<bool> vis(n, false);
        
        return dfs(0, vis, adj);
    }
    
    int dfs(int curr, vector<bool>& vis, vector<vector<int>>& adj){
        vis[curr] = true;
        int res = 0;
        
        for(int x: adj[curr]){
            if(!vis[abs(x)]){
                res += dfs(abs(x), vis, adj) + (x > 0);
            }
        }
        
        return res;
    }
};