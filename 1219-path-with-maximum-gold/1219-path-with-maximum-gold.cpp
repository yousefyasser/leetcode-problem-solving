class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> vis;
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                vis = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
                vis[i][j] = true;
                ans = max(ans, dfs(i,j,grid));         
            }
        }
        return ans;
    }
    
    int dfs(int startRow, int startCol, vector<vector<int>>& grid){
        int res = 0;
        
        for(int i = 0; i < 4; i++){
            int newRow = startRow + dx[i];
            int newCol = startCol + dy[i];
            
            if(checkInvalidPos(newRow, newCol, grid) || vis[newRow][newCol] || grid[newRow][newCol] == 0) continue;
            
            vis[newRow][newCol] = true;
            res = max(res, dfs(newRow, newCol, grid));
            vis[newRow][newCol] = false;
        }
        
        return grid[startRow][startCol] + res;
    }
    
    bool checkInvalidPos(int startRow, int startCol, vector<vector<int>>& grid){
        return startRow < 0 || startRow >= grid.size() || startCol < 0 || startCol >= grid[0].size();
    }
};