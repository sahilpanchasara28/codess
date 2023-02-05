class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> diagonal(m+n-1);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j])
                    diagonal[i+j]++;
            }
        }
        
        for(int i=1; i<m+n-2; i++)
        {
            if(diagonal[i] <  2)
                return true;
        }
        
        return false;
    }
};