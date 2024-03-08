class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 1e9, ans = 0;
        double mid = 0;
        long res = 0;
        
        while(start <= end){
            mid = start + (end-start)/2;
            res = 0;
            
            for(int i = 0; i < piles.size(); i++){
                res += ceil(piles[i]/mid);
            }
            
            if(res <= h){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        return ans;
    }
};