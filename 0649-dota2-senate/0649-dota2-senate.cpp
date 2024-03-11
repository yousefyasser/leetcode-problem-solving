class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        
        for(char c: senate) q.push(c);
        
        int r = 0, d = 0, n;
        bool change = true;
        
        while(change){
            change = false;
            n = q.size();
        
            for(int i = 0; i < n; i++){
                if(q.front() == 'R'){
                    if(d){
                        d--;
                        q.pop();
                        change = true;
                        continue;
                    }
                    r++;
                }else{
                    if(r){
                        r--;
                        q.pop();
                        change = true;
                        continue;
                    }
                    d++;
                }

                q.push(q.front());
                q.pop();
            }    
        }
                
        return q.front() == 'R' ? "Radiant" : "Dire";
    }
};