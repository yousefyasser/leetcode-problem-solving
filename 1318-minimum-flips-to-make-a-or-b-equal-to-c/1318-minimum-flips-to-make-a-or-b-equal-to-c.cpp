class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        
        while(a || b || c){
            if(((a & 1) == 1) && ((b & 1) == 1) && ((c & 1) == 0)){
                cnt += 2;
            }else if(((a | b) & 1) != (c & 1)){
                cnt++;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return cnt;
    }
};