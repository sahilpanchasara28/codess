class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        for(auto p1: points)
        {
            unordered_map<double, int> m; // slope count
            
            for(auto p2: points)
            {
                if(p1 != p2)
                {
                    int x1 = p1[0], x2 = p2[0];
                    int y1 = p1[1], y2 = p2[1];
                    
                    double slope = (double)(y2-y1)/(double)(x2-x1);
                    
                    m[slope]++;
                    
                    ans = max(ans, m[slope]);
                }
            }
        }
        
        return ans+1;
    }
};