class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        vector<int> v(grid.size(), 0);
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++)
            rows[grid[i]]++;
        
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                v[j] = grid[j][i];
            }    
            
            ans += rows[v];
        }
        return ans;
    }
};