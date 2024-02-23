class Solution {
public:
    string removeStars(string s) {
        string res = "";
        stack<char> st;
        int stars = 0;
        
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '*'){
                stars++;
                continue;
            }    
            
            if(!stars) st.push(s[i]);
            stars = max(stars-1, 0);
        }
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};