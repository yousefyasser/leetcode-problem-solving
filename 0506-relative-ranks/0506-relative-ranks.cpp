class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> ranks;
        for(int i = 0; i < score.size(); i++){
            ranks.push_back({score[i],i});
        }
        
        sort(ranks.begin(), ranks.end());
        
        int curRank = ranks.size();
        vector<string> ans(ranks.size());
        
        for(int i = 0; i < ranks.size(); i++, curRank--){
            if(curRank == 1)
                ans[ranks[i].second] = "Gold Medal";
            else if(curRank == 2)
                ans[ranks[i].second] = "Silver Medal";
            else if(curRank == 3)
                ans[ranks[i].second] = "Bronze Medal";
            else
                ans[ranks[i].second] = to_string(curRank);
        }
        
        return ans;
    }
};