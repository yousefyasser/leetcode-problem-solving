class Solution {
public:
    int maxVowels(string s, int k) {
        int Vcount = 0;
        string vowels = "aeiou";
        
        for(int i = 0; i < k; i++){
            if(vowels.find(s[i])!= std::string::npos){
                Vcount++;
            }
        }
        
        int best = Vcount;
        
        for(int i = k; i < s.length(); i++){
            if(vowels.find(s[i]) != std::string::npos) Vcount++;
            if(vowels.find(s[i-k])!= std::string::npos) Vcount--;
            best = max(Vcount, best);
        }
        
        return best;
    }
};