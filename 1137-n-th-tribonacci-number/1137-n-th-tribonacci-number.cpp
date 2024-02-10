class Solution {
public:
    int tribonacci(int n) {
        vector<int> prev;
        
        prev.push_back(0);
        prev.push_back(1);
        prev.push_back(1);
        
        if(n < 3) return prev[n];
        
        for(int i = 3; i < n; i++){
            int sum = prev[0] + prev[1] + prev[2];
            if(i % 3 == 0){
                prev[0] = sum;
            }else if(i % 3 == 1){
                prev[1] = sum;
            }else{
                prev[2] = sum;
            }
        }
        
        return prev[0] + prev[1] + prev[2];
    }
};