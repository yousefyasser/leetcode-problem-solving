class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                word += s[i];
            }else if(word.length()){
                v.push_back(word);
                word = "";
            }
        }
        if(word.length()) v.push_back(word);
        
        word = "";
        for(int i = v.size()-1; i >= 0; i--){
            word += v[i]+" ";
        }
        
        return word.substr(0, word.size()-1);
    }
};