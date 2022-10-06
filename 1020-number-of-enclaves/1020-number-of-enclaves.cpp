class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
    void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j] == 0)
            return;
            
        vis[i][j] = 1;
        
        for(int ind=0; ind<4; ind++)
            dfs(i+row[ind], j+col[ind], n, m, vis, grid);
    }
  
  
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, n, m, vis, grid);
            
            if(!vis[i][m-1] && grid[i][m-1] == 1)
                dfs(i, m-1, n, m, vis, grid);
        }
        
        for(int j=0; j<m; j++)
        {
            if(!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, n, m, vis, grid);
            
            if(!vis[n-1][j] && grid[n-1][j] == 1)
                dfs(n-1, j, n, m, vis, grid);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    ans++;
        
        return ans;
    }
};