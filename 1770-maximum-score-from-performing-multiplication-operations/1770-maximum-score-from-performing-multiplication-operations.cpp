class Solution {
public:
    
    int solve(vector<int> &a, vector<int> &b, int ind, int s, int n, int m, vector<vector<int>> &dp)
    {
        if(ind == m)
            return 0;
        
        if(dp[ind][s] != INT_MIN)
            return dp[ind][s];
        
        int op1 = b[ind]*a[s] + solve(a, b, ind+1, s+1, n, m, dp);
        int op2 = b[ind]*a[n-1-ind+s] + solve(a, b, ind+1, s, n, m, dp);
        return dp[ind][s] = max(op1, op2);
    }
    
    int maximumScore(vector<int>& a, vector<int>& b) {
        
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(m+1, vector<int> (m+1, INT_MIN));
        return solve(a, b, 0, 0, n, m, dp);
    }
};