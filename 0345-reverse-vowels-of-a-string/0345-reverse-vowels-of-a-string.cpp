class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        string vowels = "aeiouAEIOU";
        char tmp;
        
        while(i < j){
            auto it = find(vowels.begin(), vowels.end(), s[i]);
            if(it != vowels.end()){
                while(i < j){
                    it = find(vowels.begin(), vowels.end(), s[j]);
                    if(it != vowels.end()){
                        tmp = s[j];
                        s[j--] = s[i];
                        s[i] = tmp;
                        break;
                    }
                    j--;
                }
            }    
            i++;
        }
        
        return s;
    }
};