class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<vector<int>> &dp)
    {
        if(i<0 or j<0 or vis[i][j] == 1)
            return 1e9;
        
        if(i == 0 and j == 0)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
                
        int up = dfs(i-1, j, grid, vis, dp);
        int left = dfs(i, j-1, grid, vis, dp);
        
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        vector<vector<bool>> vis(n, vector<bool> (m, 0));        
        return dfs(n-1, m-1, grid, vis, dp);
    }
};