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
    
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        
        // return recursive(obstacles, 2, 0, n-1);
        
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return recursiveMem(obstacles, 2, 0, n-1, dp);
    }
};