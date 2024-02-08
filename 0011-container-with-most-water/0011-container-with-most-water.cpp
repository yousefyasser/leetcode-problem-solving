class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxArea = calcArea(i,j, height);
        
        while(i < j){
            if(height[i] <= height[j]) {
                i++;
            }else{
                j--;
            }
            
            int cand = calcArea(i, j, height);
            maxArea = max(maxArea, cand);
        }
        
        return maxArea;
    }
    
    int calcArea(int x, int y, vector<int>& height){
        return min(height[x], height[y]) * (y-x);
    }
};