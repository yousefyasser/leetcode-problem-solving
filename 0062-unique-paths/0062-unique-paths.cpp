class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m+1, vector<int>(n+1, 1));
        
        for(int i = m-1; i > 0; i--)
            for(int j = n-1; j > 0; j--)
                grid[i][j] = grid[i+1][j] + grid[i][j+1];
        
        return grid[1][1];
    }
};