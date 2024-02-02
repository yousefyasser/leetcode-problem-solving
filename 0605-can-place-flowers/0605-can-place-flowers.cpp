class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int allowed = 0;
        int consecutive = 0;
        bool first = true;
        
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i]){
                if(!first){
                    consecutive--;    
                }
                
                first = false;
                allowed += consecutive/2;
                consecutive = 0;
            }else{
                consecutive++;
            }     
        }
        
        if(first){
            consecutive++;
        }
        
        allowed += consecutive/2;
        
        return allowed >= n;
    }
};