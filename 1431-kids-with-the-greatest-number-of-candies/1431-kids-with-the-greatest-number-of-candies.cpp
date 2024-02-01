class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> greatest;
        int maximum = 0;
        
        for(int candy: candies){
            maximum = max(maximum, candy);
        }
        
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maximum) greatest.push_back(true);
            else greatest.push_back(false);
        }
        
        return greatest;
    }
};