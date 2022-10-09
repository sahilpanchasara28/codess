class Solution {
public:    
    int mod = 1000000007;
    
    int solve(int i, int j, vector<vector<int>>& grid, int k, int path, vector<vector<vector<int>>> &dp)
    {
        if(i<0 or j<0)
            return 0;
        
        if(i == 0 and j == 0)
            return (path+grid[0][0])%k == 0;
        
        if(dp[i][j][path] != -1)
            return dp[i][j][path];
        
        int up = solve(i-1, j, grid, k, (path+grid[i][j])%k, dp)%mod;
        int left = solve(i, j-1, grid, k, (path+grid[i][j])%k, dp)%mod;

        return dp[i][j][path] = (up+left)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, -1)));
        
        return solve(n-1, m-1, grid, k, 0, dp)%mod;
    }
};