int dp[101][27][101][101];

class Solution {
public:
    
    int solve(string &s, int i, int prev, int comCharLen, int k)
    {
        if(k < 0)
            return INT_MAX;
        
        if(i == s.size())
            return 0;
        
        if(dp[i][prev][comCharLen][k] != -1)
            return dp[i][prev][comCharLen][k];
        
        int notKeep = solve(s, i+1, prev, comCharLen, k-1);
        int keep = 0;
        
        if(s[i]-'a' == prev)
        {
            keep = solve(s, i+1, prev, comCharLen+1, k);
            if(comCharLen == 1 or comCharLen == 9 or comCharLen == 99)
                keep++;
        }
        else
            keep = 1 + solve(s, i+1, s[i]-'a', 1, k);
        
        return dp[i][prev][comCharLen][k] = min(keep, notKeep);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        
        
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 26, 0, k);
    }
};