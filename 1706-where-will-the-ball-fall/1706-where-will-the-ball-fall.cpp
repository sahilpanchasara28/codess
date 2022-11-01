class Solution {
public:
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid)
    {
        if(i == n)
            return j;
        
        int nj = j + grid[i][j];
        
        if(nj < 0 or nj >= m or grid[i][j] != grid[i][nj])
            return -1;
        
        return dfs(i+1, nj, n, m, grid);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0);
        
        for(int j=0; j<m; j++)
            ans[j] = dfs(0, j, n, m, grid);
        
        return ans;
    }
};