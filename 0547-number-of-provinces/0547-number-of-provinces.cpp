class Solution {
public:
    vector<bool> vis;
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vis = vector<bool>(isConnected.size(), false);
        int cnt = 0;
        
        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]) {
                cnt++;
                dfs(i, isConnected);
            }
        }
        
        return cnt;
    }
    
    void dfs(int curr, vector<vector<int>>& isConnected){
        vis[curr] = true;
        
        for(int i = 0; i < isConnected[curr].size(); i++){
            if(isConnected[curr][i] && !vis[i]){
                dfs(i, isConnected);
            }
        }
    }
};