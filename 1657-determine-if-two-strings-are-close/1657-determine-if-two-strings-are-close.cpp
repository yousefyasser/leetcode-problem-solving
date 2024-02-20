class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<int, int> m1, m2, count;
        for(auto& i : word1) m1[i]++;
        for(auto& i : word2) m2[i]++;
        
        for(auto it = m1.begin(); it != m1.end(); it++){
            if(!m2.count(it->first)) return false;
            count[it->second]++;
        }
        for(auto it = m2.begin(); it != m2.end(); it++){
            if(!count[it->second]--) return false;
            if(!m1.count(it->first)) return false;
        }
        
        return true;
    }
};