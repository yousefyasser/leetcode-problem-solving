class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int count = 1;
        int j = 1;
        int k;
        
        for(int i = 0; i < chars.size()-1; i++){
            if(chars[i] == chars[i+1]) count++;
            else{
                chars[j-1] = chars[i];
                res += addCountToArray(chars, count, j);
                
                if(count > 1) j++;
                if(count > 9) j++;
                if(count > 99) j++;
                if(count > 999) j++;
                
                count = 1;
                j++;
            }
        }
        
        chars[j-1] = chars[chars.size()-1];
        res += addCountToArray(chars, count, j);
        
        return res;
    }
    
    int addCountToArray(vector<char>& chars, int count, int j){
        int res = 0;
        int k = -1;
        
        if(count > 999) k = 3;
        else if(count > 99) k =2;
        else if(count > 9) k = 1;
        else if(count > 1) k = 0;

        while(k >= 0){
            chars[j + k--] = '0' + (count % 10);
            count /= 10;
            res++;
        }
        res++;
        return res;
    }
};