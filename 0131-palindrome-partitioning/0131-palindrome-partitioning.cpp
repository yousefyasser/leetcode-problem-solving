class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        
        for(int i = 1; i <= s.length(); i++){
            string part1 = s.substr(0, i);
            
            if(isPal(part1)){
                vector<vector<string>> part2 = partition(s.substr(i, s.length() - i));
                
                if(part2.size() == 0){
                    part2 = {{part1}};
                }else{
                    for(vector<string>& x: part2){
                        vector<string> res = {part1};
                        res.insert(res.end(), x.begin(), x.end());
                        x = res;
                    }   
                }
                
                ans.insert(ans.end(), part2.begin(), part2.end());
            }
        }
        
        return ans;
    }
    
    bool isPal(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};