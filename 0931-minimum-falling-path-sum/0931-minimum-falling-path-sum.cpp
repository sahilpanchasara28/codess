class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& mat, int n, vector<vector<int>> &dp)
    {
        if(i >= n or j < 0 or j >= n)
            return 1e9;
        
        if(i == mat.size()-1)
            return mat[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int op1 = solve(i+1, j+1, mat, n, dp);
        int op2 = solve(i+1, j, mat, n, dp);
        int op3 = solve(i+1, j-1, mat, n, dp);
        
        return dp[i][j] = mat[i][j] + min(op1, min(op2, op3));
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int j=0; j<n; j++)
            mini = min(mini, solve(0, j, mat, n, dp));
        
        return mini;
    }
};