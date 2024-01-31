
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res("");
        int i(0);
        
        for(; i < min(word1.length(), word2.length()); i++){
            res = res + word1[i] + word2[i];
        }
        
        if(word1.length() < word2.length()){
            res = res + word2.substr(i);
        }else{
            res = res + word1.substr(i);
        }
        
        return res;
    }
};