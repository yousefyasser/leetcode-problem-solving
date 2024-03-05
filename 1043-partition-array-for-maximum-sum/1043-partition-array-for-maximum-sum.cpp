class Solution {
public:
    vector<vector<long>> memo;
    vector<long> dp;
    int s;
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo = vector<vector<long>>(k+1, vector<long>(arr.size()+1, -1));
        dp = vector<long>(arr.size()+1, -1);
        s = k;
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= arr.size()-i+1; j++){
                int ma = -1;
                
                for(int k = j-1; k < j+i-1; k++){
                    ma = max(ma, arr[k]);
                }
                memo[i][j] = ma*i;

                cout << memo[i][j] << " ";
            }
            cout << endl;
        }
    
        return trial(1);
    }
    
    long trial(int idx){
        if(idx > dp.size()-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        long ma = 0, cand;
        
        for(int i = 1; i <= s; i++){
            cand = trial(idx+i) + memo[i][idx];   
            ma = max(ma, cand);
        }
        
        return dp[idx] = ma;
    }
};