class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        
        memo[0][0] = 1 - obstacleGrid[0][0];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] || (i == 0 && j == 0)){
                    continue;
                }

                if(i == 0 && j!= 0){
                    memo[i][j] = memo[i][j-1];
                    continue;
                }
                if(j == 0 && i != 0){
                    memo[i][j] = memo[i-1][j];
                    continue;
                }
                
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        
        return memo[m-1][n-1];
    }
};