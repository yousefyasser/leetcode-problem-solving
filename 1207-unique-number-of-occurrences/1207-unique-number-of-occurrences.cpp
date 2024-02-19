class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        unordered_set<int> s;
        
        for(auto& i: arr) mp[i]++;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(s.count(it->second)) return false;
            s.insert(it->second);
        }
        return true;
    }
};