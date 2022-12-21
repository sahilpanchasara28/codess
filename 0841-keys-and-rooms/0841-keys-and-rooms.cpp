class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<bool> unlocked(n, 0);
        unlocked[0] = 1;
        
        stack<int> s;
        s.push(0);
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            
            for(auto i: rooms[top])
            {
                if(!unlocked[i])
                {
                    unlocked[i] = 1;
                    s.push(i);
                }
            }
        }
        
        for(auto i: unlocked)
            if(!i)
                return false;
        
        return true;
    }
};