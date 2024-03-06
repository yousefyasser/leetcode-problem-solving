class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        
        for(auto x: spells){
            long long target = (success / x) - (success % x == 0);
            
            int l = 0;
            int r = potions.size()-1;
            int mid = 0;
            int ans = potions.size();
            
            while(l <= r){
                mid = l + (r-l)/2;
                
                if(potions[mid] > target){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            
            res.push_back(potions.size() - ans);
        }
        
        return res;
    }
};