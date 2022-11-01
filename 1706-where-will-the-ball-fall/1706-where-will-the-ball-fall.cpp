class Solution {
public:
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i == n)
            return j;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int nj = j + grid[i][j];
        
        if(nj < 0 or nj >= m or grid[i][j] != grid[i][nj])
            return -1;
        
        return dp[i][j] = dfs(i+1, nj, n, m, grid, dp);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0);
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int j=0; j<m; j++)
            ans[j] = dfs(0, j, n, m, grid, dp);
        
        return ans;
    }
};