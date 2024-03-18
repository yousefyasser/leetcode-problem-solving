class Solution {
public:
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<bool>> vis(maze.size(), vector<bool>(maze[0].size(), false));
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});
        
        while(!q.empty()){
            pair<int, pair<int, int>> curr = q.front();
            q.pop();
            
            int currRow = curr.second.first;
            int currCol = curr.second.second;
            
            if(currRow < 0 || currRow >= maze.size() || currCol < 0 || currCol >= maze[0].size())
                continue;
            
            if(maze[currRow][currCol] == '+' || vis[currRow][currCol])
                continue;
            
            if(!(currRow == entrance[0] && currCol == entrance[1]))
                if(currRow == 0 || currRow + 1 == maze.size() || currCol == 0 || currCol + 1 == maze[0].size())
                    return curr.first;
            
            vis[currRow][currCol] = true;
            for(int i = 0; i < 4; i++){
                q.push({curr.first + 1, {currRow + dx[i], currCol + dy[i]}});
            }
        }
        
        return -1;
    }
};