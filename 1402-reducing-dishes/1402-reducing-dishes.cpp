class Solution {
public:
    int recursive(vector<int> &sat, int ind, int time)
    {
        if(ind == sat.size())
            return 0;
        
        int include = sat[ind]*(time+1) + recursive(sat, ind+1, time+1);
        int exclude = recursive(sat, ind+1, time);
        
        return max(include, exclude);
    }
    
    int recursiveMem(vector<int> &sat, int ind, int time, vector<vector<int>> &dp)
    {
        if(ind == sat.size())
            return 0;
        
        if(dp[ind][time] != -1)
            return dp[ind][time];
        
        int include = sat[ind]*(time+1) + recursiveMem(sat, ind+1, time+1, dp);
        int exclude = recursiveMem(sat, ind+1, time, dp);
        
        return dp[ind][time] = max(include, exclude);
    }
    
    int tabulation(vector<int> &sat)
    {
        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int time=ind; time>=0; time--)
            {
                int include = sat[ind]*(time+1) + dp[ind+1][time+1];
                int exclude = dp[ind+1][time];

                dp[ind][time] = max(include, exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int spaceOptimised(vector<int> &sat)
    {
        int n = sat.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int time=ind; time>=0; time--)
            {
                int include = sat[ind]*(time+1) + next[time+1];
                int exclude = next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        
        return curr[0];
    }
    
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        
        // return recursive(sat, 0, 0);
        
        // int n = sat.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return recursiveMem(sat, 0, 0, dp);
        
        // return tabulation(sat);
        
        return spaceOptimised(sat);
    }
};