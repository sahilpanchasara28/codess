class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid)
    {    
        grid[i][j] = '2';
        
        if(i != 0 && grid[i-1][j] == '1') dfs(i-1, j, n, m, grid);
        if(i != n-1 && grid[i+1][j] == '1') dfs(i+1, j, n, m, grid);
        if(j != 0 && grid[i][j-1] == '1') dfs(i, j-1, n, m, grid);
        if(j != m-1 && grid[i][j+1] == '1') dfs(i, j+1, n, m, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        
        return ans;
    }
};