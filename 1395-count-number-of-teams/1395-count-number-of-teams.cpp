class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        
        for(int i = 1; i < rating.size()-1; i++){
            int smallerBefore = 0, largerBefore = 0, smallerAfter = 0, largerAfter = 0;
            
            for(int j = 0; j < i; j++){
                smallerBefore += rating[j] < rating[i];
                largerBefore += rating[j] > rating[i];
            }
            
            for(int j = i+1; j < rating.size(); j++){
                smallerAfter += rating[j] < rating[i];
                largerAfter += rating[j] > rating[i];
            }
            
            res += smallerBefore * largerAfter + largerBefore * smallerAfter;
        }
        
        return res;
    }
};