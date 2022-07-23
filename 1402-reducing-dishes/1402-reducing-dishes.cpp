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
    
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        
        // return recursive(sat, 0, 0);
        int n = sat.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recursiveMem(sat, 0, 0, dp);
    }
};