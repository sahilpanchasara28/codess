#define mod 1000000007

class Solution {
public:
    
    int recursive(int faces, int dice, int target)
    {
        if(target < 0)
            return 0;
        
        if(dice == 0 && target != 0)
            return 0;
        
        if(target == 0 && dice != 0)
            return 0;   
        
        if(dice == 0 && target == 0)
            return 1;
        
        int count = 0;
        for(int face=1; face<=faces; face++)
            count = (count + recursive(faces, dice-1, target-face)%mod)%mod;
        return count%mod;
    }
    
    int recursiveMem(int faces, int dice, int target, vector<vector<int>> &dp)
    {
        if(target < 0)
            return 0;
        
        if(dice == 0 && target != 0)
            return 0;
        
        if(target == 0 && dice != 0)
            return 0;
        
        if(dice == 0 && target == 0)
            return 1;
        
        if(dp[dice][target] != -1)
            return dp[dice][target];
        
        int count = 0;
        for(int face=1; face<=faces; face++)
            count = (count + recursiveMem(faces, dice-1, target-face, dp)%mod)%mod;
        return dp[dice][target] = count%mod;
    }
    
    int tabulation(int m, int n, int x)
    {
        vector<vector<int>> dp(n+1, vector<int> (x+1, 0));
        
        dp[0][0] = 1;
        
        for(int dice=1; dice<=n; dice++)
        {
            for(int target=1; target<=x; target++)
            {
                int count = 0;
                for(int face=1; face<=m; face++)
                    if(target-face >= 0)
                        count = (count + dp[dice-1][target-face]%mod)%mod;
                dp[dice][target] = count%mod;
            }
        }
        
        return dp[n][x]%mod;
    }
    
    int spaceOptimised(int m, int n, int x)
    {
        vector<int> prev(x+1, 0);
        vector<int> curr(x+1, 0);
        
        prev[0] = 1;
        
        for(int dice=1; dice<=n; dice++)
        {
            for(int target=1; target<=x; target++)
            {
                long long count = 0;
                for(int face=1; face<=m; face++)
                    if(target-face >= 0)
                        count = (count + prev[target-face]%mod)%mod;
                curr[target] = count%mod;
            }
            prev = curr;
        }
        
        return prev[x]%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return recursive(k, n, target);
        
        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        // return recursiveMem(k, n, target, dp);
        
        // return tabulation(k, n, target);
        
        return spaceOptimised(k, n, target);
    }
};