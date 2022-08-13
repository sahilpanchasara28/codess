#define mod 1000000007
class Solution {
public:
   

int recursive(string &t, string &s, int i, int j)
{
    if(j < 0)
        return 1;
    
    if(i < 0)
        return 0;

    if(t[i] == s[j])
    {
        int op1 = recursive(t, s, i-1, j-1)%mod;
        int op2 = recursive(t, s, i-1, j)%mod;
        return (op1+op2)%mod;
    }
    else
        return recursive(t, s, i-1, j)%mod;
}

int recursiveMem(string &t, string &s, int i, int j, vector<vector<int>> &dp)
{
    if(j < 0)
        return 1;
    
    if(i < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(t[i] == s[j])
    {
        int op1 = recursiveMem(t, s, i-1, j-1, dp)%mod;
        int op2 = recursiveMem(t, s, i-1, j, dp)%mod;
        return dp[i][j] = (op1+op2)%mod;
    }
    else
        return dp[i][j] = recursiveMem(t, s, i-1, j, dp)%mod;
}

int tabulation(string &t, string &s, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(t[i-1] == s[j-1])
            {
                int op1 = dp[i-1][j-1]%mod;
                int op2 = dp[i-1][j]%mod;
                dp[i][j] = (op1+op2)%mod;
            }
            else
                dp[i][j] = dp[i-1][j]%mod;
        }
    }
    
    return dp[n][m];
}

int space(string &t, string &s, int n, int m)
{
    vector<int> prev(m+1, 0);
    vector<int> curr(m+1, 0);
    
    prev[0] = curr[0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(t[i-1] == s[j-1])
            {
                int op1 = prev[j-1]%mod;
                int op2 = prev[j]%mod;
                curr[j] = (op1+op2)%mod;
            }
            else
                curr[j] = prev[j]%mod;
        }
        prev = curr;
    }
    
    return prev[m];
}

int spaceMore(string &t, string &s, int n, int m)
{
    vector<int> curr(m+1, 0);
    
    curr[0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=m; j>=1; j--)
        {
            if(t[i-1] == s[j-1])
            {
                int op1 = curr[j-1]%mod;
                int op2 = curr[j]%mod;
                curr[j] = (op1+op2)%mod;
            }
            else
                curr[j] = curr[j]%mod;
        }
    }
    
    return curr[m];
}
    
    int numDistinct(string t, string s) {
        int lt = t.size();
        int ls = s.size();
        
            // return recursive(t, s, lt-1, ls-1);
    
    // vector<vector<int>> dp(lt, vector<int>(ls, -1));
    // return recursiveMem(t, s, lt-1, ls-1, dp);
    
    // return tabulation(t, s, lt, ls);
    
    return space(t, s, lt, ls);
    
    // return spaceMore(t, s, lt, ls);
    }
};