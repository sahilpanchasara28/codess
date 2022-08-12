class Solution {
public:
    int recursive(string s, string t, int i, int j)
{
    if(i < 0 || j < 0)
        return 0;
    
    if(s[i] == t[j])
    {
        int call = 1 + recursive(s, t, i-1, j-1);
        return call;
    }
    else
    {
        int op1 = recursive(s, t, i, j-1);
        int op2 = recursive(s, t, i-1, j);
        return max(op1, op2);
    }
}

int recursiveMem(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if(i < 0 || j < 0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == t[j])
    {
        int call = 1 + recursiveMem(s, t, i-1, j-1, dp);
        return dp[i][j] = call;
    }
    else
    {
        int op1 = recursiveMem(s, t, i, j-1, dp);
        int op2 = recursiveMem(s, t, i-1, j, dp);
        return dp[i][j] = max(op1, op2);
    }
}

int tabulation(string s, string t, int n)
{
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                int op1 = dp[i][j-1];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    
    return dp[n][n];
}

int space(string s, string t, int n)
{
    vector<int> curr(n+1, 0);
    vector<int> prev(n+1, 0);
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1] == t[j-1])
                curr[j] = 1 + prev[j-1];
            else
            {
                int op1 = curr[j-1];
                int op2 = prev[j];
                curr[j] = max(op1, op2);
            }
        }
        prev = curr;
    }
    
    return prev[n];
}
    
    int longestPalindromeSubseq(string s) {
    int n = s.size();
        
    string t = s;
    reverse(t.begin(), t.end());
        
    // return recursive(s, t, n-1, n-1);
    
    // vector<vector<int>> dp(n, vector<int> (n, -1));
    // return recursiveMem(s, t, n-1, n-1, dp);
    
    return tabulation(s, t, n);
    
    // return space(s, t, n);
    }
};