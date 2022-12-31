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
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return dfs(0, 0, n, m, grid, dp);
    }
};