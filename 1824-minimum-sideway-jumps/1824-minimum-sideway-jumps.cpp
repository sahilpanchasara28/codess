class Solution {
public:
    
    int recursive(vector<int> &obs, int currLane, int pos, int n)
    {
        if(pos == n)
            return 0;
        
        if(obs[pos+1] != currLane)
            return recursive(obs, currLane, pos+1, n);
        else
        {
            // sideway jumps
            int ans = INT_MAX;
            for(int lane=1; lane<=3; lane++)
            {
                if(currLane != lane && obs[pos] != lane)
                    ans = min(ans, 1 + recursive(obs, lane, pos, n));
            }
            return ans;
        }
    }
    
    int recursiveMem(vector<int> &obs, int currLane, int pos, int n, vector<vector<int>> &dp)
    {
        if(pos == n)
            return 0;
        
        if(dp[currLane][pos] != -1)
            return dp[currLane][pos];
        
        if(obs[pos+1] != currLane)
            return recursiveMem(obs, currLane, pos+1, n, dp);
        else
        {
            // sideway jumps
            int ans = INT_MAX;
            for(int lane=1; lane<=3; lane++)
            {
                if(currLane != lane && obs[pos] != lane)
                    ans = min(ans, 1 + recursiveMem(obs, lane, pos, n, dp));
            }
            return dp[currLane][pos] = ans;
        }
    }
    
    int tabulation(vector<int> &obs, int n)
    {
        vector<vector<int>> dp(4, vector<int> (n, 1e9));
        
        for(int lane=1; lane<=3; lane++)
            dp[lane][n-1] = 0;
        
        for(int pos=n-2; pos>=0; pos--)
        {
            for(int currLane=1; currLane<=3; currLane++)
            {
                 if(obs[pos+1] != currLane)
                    dp[currLane][pos] = dp[currLane][pos+1];
                else
                {
                    // sideway jumps
                    int ans = 1e9;
                    for(int lane=1; lane<=3; lane++)
                    {
                        if(currLane != lane && obs[pos] != lane)
                            ans = min(ans, 1 + dp[lane][pos+1]);
                    }
                    dp[currLane][pos] = ans;
                }
            }
        }
        
        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));
    }
    
    int spaceOptimised(vector<int> &obs, int n)
    {
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);
        
        for(int lane=1; lane<=3; lane++)
            next[lane] = 0;
        
        for(int pos=n-2; pos>=0; pos--)
        {
            for(int currLane=1; currLane<=3; currLane++)
            {
                 if(obs[pos+1] != currLane)
                    curr[currLane] = next[currLane];
                else
                {
                    // sideway jumps
                    int ans = 1e9;
                    for(int lane=1; lane<=3; lane++)
                    {
                        if(currLane != lane && obs[pos] != lane)
                            ans = min(ans, 1 + next[lane]);
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        
        return min(curr[2], min(curr[1]+1, curr[3]+1));
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        
        // return recursive(obstacles, 2, 0, n-1);
        
        // vector<vector<int>> dp(4, vector<int>(n, -1));
        // return recursiveMem(obstacles, 2, 0, n-1, dp);
        
        // return tabulation(obstacles, n);
        
        return spaceOptimised(obstacles, n);
    }
};