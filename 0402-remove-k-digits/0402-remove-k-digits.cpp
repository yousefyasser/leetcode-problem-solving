class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length())
            return "0";
        
        stack<char> s;
        for(char c: num){
            while(!s.empty() && s.top() > c && k){
                s.pop();
                k--;
            }
            s.push(c);
        }
        
        string res = "";
        while(!s.empty()){
            if(k) {
                s.pop();
                k--;
                continue;
            }
            
            res += s.top();
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        string ans = "";
        bool first = false;
        
        for(char c: res){
            if(c == '0' && !first) continue;
            first = true;
            ans += c;
        }
        
        return (ans == "") ? "0" : ans;
    }
};