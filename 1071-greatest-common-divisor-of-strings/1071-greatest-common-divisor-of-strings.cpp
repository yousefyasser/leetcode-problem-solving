class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int gcd = std::gcd(str1.length(), str2.length());

        string pattern = str1.substr(0,gcd);

        bool ok1 = containsPattern(str1, pattern);
        if(!ok1) return "";

        bool ok2 = containsPattern(str2, pattern);
        if(!ok2) return "";
        
        return pattern;
    }
    
    bool containsPattern(string str, string pattern){
        int i = pattern.length();
        
        for(int j = 0; j < str.length(); j += i){
            if(str.substr(j, i) != pattern) return false;        
        }
        
        return true;
    }
};