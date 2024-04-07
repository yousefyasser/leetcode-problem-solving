class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = min(2, int(points.size()));
        map<int, int> vertical;
        
        for(int i = 0; i < points.size(); i++){
            map<double, int> gradients;
            vertical[points[i][0]]++;
                
            for(int j = 0; j < points.size(); j++){
                if(i == j || points[i][0] == points[j][0]) 
                    continue;
                
                double grad = calcGradient(points[i], points[j]);
                gradients[grad]++;  
            }
            
            for(auto it = gradients.begin(); it != gradients.end(); it++){
                ans = max(ans, it->second + 1);
            }
        }
        
        for(auto it = vertical.begin(); it != vertical.end(); it++){
            ans = max(ans, it->second);
        }
        
        return ans;
    }
    
    double calcGradient(vector<int> p1, vector<int> p2){
        return (p1[1] - p2[1]) / (double)(p1[0] - p2[0]);
    }
};