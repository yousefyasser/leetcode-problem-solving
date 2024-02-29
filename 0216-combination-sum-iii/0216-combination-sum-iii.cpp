class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        trial(k, 0, n, {}, res);
        return res;
    }
    void trial(int k, int idx, int n, vector<int> curr, vector<vector<int>>& res){
        if(n < 0) return;
        if(idx == k){
            if(n == 0) res.push_back(curr);
            return;
        }
        
        int start = 1;
        if(curr.size()){
            start = curr[curr.size()-1];
        }
        
        for(int i = start; i <= 9; i++){
            if(count(curr.begin(), curr.end(), i) > 0) continue;
            
            curr.push_back(i);
            trial(k, idx+1, n-i, curr, res);
            curr.pop_back();
        }
    }
};