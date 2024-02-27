class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string res = "";

        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '['){
                continue;
            }else if(s[i] == ']'){
                st.push("]");
            }else if(s[i] >= '0' && s[i] <= '9'){
                string num = "";

                while(i >= 0 && s[i] >= '0' && s[i] <= '9'){
                    num = s[i--] + num;
                }
                i++;
                
                int x = stoi(num);
                string word = "";
                
                while(st.top() != "]"){
                    word += st.top();
                    st.pop();
                }
                st.pop();
                
                while(x--){
                    st.push(word);
                }
            }else{
                string str = "";
                str += s[i];
                st.push(str);
            }
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};