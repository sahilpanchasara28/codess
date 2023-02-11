class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxDist = 2*n + 1;
        
        vector<vector<int>> dist(n, vector<int> (n, maxDist));
        
        // iterate top and left
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                    dist[i][j] = 0;
                else
                {
                    int left = (i > 0) ? dist[i-1][j] + 1 : maxDist;
                    int top = (j > 0) ? dist[i][j-1] + 1 : maxDist;
                    dist[i][j] = min(dist[i][j], min(left, top));
                }
            }
        }
        
        int ans = INT_MIN;
        
        // iterate right and bottom
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {

                int right = (i < n-1) ? dist[i+1][j] + 1 : maxDist;
                int bottom = (j < n-1) ? dist[i][j+1] + 1 : maxDist;
                dist[i][j] = min(dist[i][j], min(right, bottom));
                ans = max(ans, dist[i][j]);
            }
        }
        
        return (ans == 0 or ans == maxDist) ? -1 : ans;
    }
};