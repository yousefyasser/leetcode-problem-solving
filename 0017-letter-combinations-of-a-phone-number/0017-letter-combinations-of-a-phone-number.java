import java.util.ArrayList;

class Solution {
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return new ArrayList<String>();

        List<String> out = new ArrayList<String>();
        String first = getChars(digits.charAt(0));
        
        for(char c: first.toCharArray()){
            out.add(c + "");
        }

        out = solve(digits, 1, out);
        return out;
    }

    public static String getChars(char c){
        int n = c - '0';
        String alpha = "abcdefghijklmnopqrstuvwxyz";
        int tmp = n-2;

        for(int i = 0; i < alpha.length()-4; i+=3, tmp--){
            if(tmp == 0){
                if(n >= 8) i++;
                if(n == 7 || n == 9){
                    return alpha.substring(i, i+4);
                }
                return alpha.substring(i, i+3);
            }
        }

        return "";
    }
    
    public static List<String> solve(String in, int currPos, List<String> ans){
        if(currPos == in.length()){
            return ans;
        }

        String currString = getChars(in.charAt(currPos));
        List<String> tmp = new ArrayList<String>();

        for(String item: ans){
            for(char c: currString.toCharArray()){
                String newStr = item + c;
                tmp.add(newStr);
            }
        }

        return solve(in, currPos+1, tmp);
    }
}
