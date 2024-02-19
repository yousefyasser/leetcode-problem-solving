class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        map<int, int> m2;
        vector<vector<int>> res(2, vector<int>());
        
        for(auto& i: nums1) m1[i]++;
        for(auto& i: nums2) {
            m2[i]++;
            if(!m1.count(i)){
                res[1].push_back(i);
                m1[i] = 1;
            }
        }
        for(auto& i: nums1) {
            if(!m2.count(i)){
                m2[i] = 1;
                res[0].push_back(i);
            }
        }
        
        return res;
    }
};