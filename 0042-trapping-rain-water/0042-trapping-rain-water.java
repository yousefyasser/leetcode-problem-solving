class Solution {
    public int trap(int[] height) {
        int maxSoFar = height[0];
        int water = 0;
        
//         outer: for(int i = 1; i < height.length; i++){
//             if(height[i] >= maxSoFar){
//                 maxSoFar = height[i];
//             }else{
//                 boolean bool = false;
//                 for(int j = i+1; j < height.length; j++){
//                     if(height[j] >= maxSoFar){
//                         water += maxSoFar - height[i];
//                         continue outer;
//                     }
//                 }
                
//                 for(int j = i+1; j < height.length; j++){
//                     if(height[j] >= height[i] && height[i-1] > height[i]){
//                         water += height[i-1] - height[i];
//                         break;
//                     }
//                 }
//             }
//         }
        
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