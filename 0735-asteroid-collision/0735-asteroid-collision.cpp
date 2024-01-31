#include <stack>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s, ans;
        vector<int> v;
        s.push(asteroids[0]);
        
        for(int i = 1; i < asteroids.size(); i++){
            // current and previous asteroids does not meet
            if(s.empty() || s.top() < 0 || asteroids[i] * s.top() > 0){
                s.push(asteroids[i]);
                continue;
            }
            
            // current and previous asteroids meet
            bool first = true;
            bool skip = false;
            
            while(!s.empty() && !(s.top() < 0 || asteroids[i] * s.top() > 0)){
                if(abs(asteroids[i]) > abs(s.top())){
                    s.pop();
                }else if(abs(asteroids[i]) == abs(s.top())){
                    s.pop();
                    skip = true;
                    break;
                }else{
                    skip = true;
                    break;
                }
                first = false;
            }
            
            if(!skip){
                s.push(asteroids[i]);
            }
        }
        
        // reverse order of output to return it in the correct order
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }
        
        while(!ans.empty()){
            v.push_back(ans.top());
            ans.pop();
        }
        
        return v;
    }
};