class Solution {
    public int trap(int[] height) {
        int water = 0;
        
        for(int i = 1; i < height.length; i++){
            int maxBefore = -1;
            for(int j = 0; j < i; j++){
                maxBefore = Math.max(maxBefore, height[j]);
            }
            
            int maxAfter = -1;
            for(int j = i+1; j < height.length; j++){
                maxAfter = Math.max(maxAfter, height[j]);
            }
            
            int min = Math.min(maxBefore, maxAfter);
            
            water += Math.max(min - height[i], 0);
        }
        return water;
    }
}