class Solution {
public:
    vector<bool> vis;
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        vis = vector<bool>(rooms.size(), false);
        
        s.push(0);
        
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            
            vis[curr] = true;
            for(int i = 0; i < rooms[curr].size(); i++){
                if(!vis[rooms[curr][i]]){
                    s.push(rooms[curr][i]);
                }
            }
        }
        
        bool ans = true;
        for(bool x: vis) ans &= x;
        
        return ans;
    }
};