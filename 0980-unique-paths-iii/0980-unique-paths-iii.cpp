class Solution {
public:
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int emptyCell)
    {
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == -1 or grid[i][j] == 3)
            return 0;
        
        if(grid[i][j] == 2)
            return (emptyCell == 0) ? 1 : 0;
        
        grid[i][j] = 3; // marking visited
        
        int up = dfs(i-1, j, n, m, grid, emptyCell-1);
        int down = dfs(i+1, j, n, m, grid, emptyCell-1);
        int left = dfs(i, j-1, n, m, grid, emptyCell-1);
        int right = dfs(i, j+1, n, m, grid, emptyCell-1);
        
        grid[i][j] = 0; // backtracking
        return up+down+left+right;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int emptyCell = 0;
        int row = 0, col = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0)
                    emptyCell++;
                else if(grid[i][j] == 1)
                {
                    row = i;
                    col = j;
                }
            }
        }
        
        return dfs(row, col, n, m, grid, emptyCell+1);
    }
};