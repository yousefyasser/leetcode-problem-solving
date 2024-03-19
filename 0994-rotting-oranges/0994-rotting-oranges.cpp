class Solution {
public:
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int count = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; i++){
                pair<int, int> curr = q.front();
                q.pop();
                
                for(int j = 0; j < 4; j++){
                    int newX = curr.first + dx[j];
                    int newY = curr.second + dy[j];
                    
                    if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size())
                        continue;
                    
                    if(grid[newX][newY] == 1){
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                    }
                }
            }
            
            count++;
        }
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return max(0, count-1);
    }
};