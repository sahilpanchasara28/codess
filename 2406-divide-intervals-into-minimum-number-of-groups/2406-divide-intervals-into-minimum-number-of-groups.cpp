class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        
        map<int, int> m;
        int c = 0, r = 0;
        
        for(auto &i: arr)
        {
            m[i[0]]++;
            m[i[1]+1]--;
        }
        
        for(auto &i: m)
            r = max(r, c+=(i.second));
        
        return r;
    }
};