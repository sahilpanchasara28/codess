class Solution {
public:
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i>=n or j>=m or grid[i][j] == 1 or grid[i][j] == 3)
            return 0;
        
        if(i == n-1 and j == m-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        grid[i][j] = 3; // marking visited
        
        int down = dfs(i+1, j, n, m, grid, dp);
        int right = dfs(i, j+1, n, m, grid, dp);
        
        grid[i][j] = 0; // backtracking
        return dp[i][j] = down+right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] == 1 or grid[n-1][m-1] == 1) 
            return 0; 
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
                
        dp[0][0] = 1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if((i == 0 and j == 0) or grid[i][j] == 1)
                    continue;
                else
                {
                    int down = (i > 0) ? dp[i-1][j] : 0;
                    int right = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = down+right;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};