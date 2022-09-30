class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> edge;
        for(auto i: buildings)
        {
            edge.push_back({i[0], -i[2]});
            edge.push_back({i[1], i[2]});
        }
        
        sort(edge.begin(), edge.end());
        
        multiset<int> m;
        m.insert(0);
        int prev = 0, curr = 0;
        
        vector<vector<int>> ans;
        
        for(auto i: edge)
        {
            if(i.second < 0) // left point
                m.insert(-i.second);
            else
                m.erase(m.find(i.second));
        
            curr = *(m.rbegin());
            
            if(curr != prev)
            {
                ans.push_back({i.first, curr});
                prev = curr;
            }
        }
        
        return ans;
    }
};