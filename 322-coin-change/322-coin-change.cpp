class Solution {
public:
    int recursive(vector<int> &coins, int amt)
    {
        if(amt < 0)
            return 1e9;
        
        if(amt == 0)
            return 0;
        
        int ans = 1e9;
        for(int c: coins)
            ans = min(ans, 1+recursive(coins, amt-c));
        
        return ans;
    }
    
    int recursiveMem(vector<int> &coins, int amt, vector<int> &dp)
    {
        if(amt < 0)
            return 1e9;
        
        if(amt == 0)
            return 0;
        
        if(dp[amt] != -1)
            return dp[amt];
        
        int ans = 1e9;
        for(int c: coins)
            ans = min(ans, 1+recursiveMem(coins, amt-c, dp));
        
        return dp[amt] = ans;
    }
    
    int coinChange(vector<int>& coins, int amt) {
        // int ans = recursive(coins, amt);
        
        vector<int> dp(amt+1, -1);
        int ans = recursiveMem(coins, amt, dp);
        
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};