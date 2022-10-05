class Solution {
public:
    
    void dfs(int i, int j, int n, int m, vector<vector<char>> &mat, vector<vector<bool>> &vis)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || mat[i][j] == 'X')
            return;
        
        vis[i][j] = 1;

        dfs(i-1, j, n, m, mat, vis);
        dfs(i+1, j, n, m, mat, vis);
        dfs(i, j-1, n, m, mat, vis);
        dfs(i, j+1, n, m, mat, vis);
    }
    
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        
        for(int j=0; j<m; j++)
        {
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, n, m, mat, vis);
                
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1, j, n, m, mat, vis);
        }
                
        for(int i=1; i<n-1; i++)
        {
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, n, m, mat, vis);
                
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, n, m, mat, vis);
        }
                
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';                    
    }
};