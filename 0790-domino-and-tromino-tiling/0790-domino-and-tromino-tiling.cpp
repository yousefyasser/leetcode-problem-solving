class Solution {
public:
    int numTilings(int n) {
        vector<int> x;
        x.push_back(1);
        x.push_back(2);
        x.push_back(5);
        
        long MOD = 1e9 + 7;
        
        for(int i = 3; i < n; i++){
            int res = ((2*x[i-1] % MOD) + x[i-3]) % MOD;
            x.push_back(res);
        }
        
        
        return x[n-1];
    }
};