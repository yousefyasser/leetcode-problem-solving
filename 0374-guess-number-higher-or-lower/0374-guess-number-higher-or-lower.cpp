/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = (1l << 31)-1, mid;
        int res;
        
        while(l <= r){
            mid = l + (r-l)/2;
            res = guess(mid);
            
            if(res == -1)
                r = mid - 1;
            else if(res == 0)
                return mid;
            else
                l = mid+1;
        }
        
        return l;
    }
};