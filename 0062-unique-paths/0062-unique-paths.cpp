class Solution {
public:
    int uniquePaths(int n, int m) {

        vector<vector<int>> dp(n, vector<int> (m, 0));
                
        dp[0][0] = 1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i == 0 and j == 0)
                    continue;
                else
                {
                    int down = (i > 0) ? dp[i-1][j] : 0;
                    int right = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = down+right;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};