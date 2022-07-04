class Solution {
public:
    int solve(int n, vector<int> &cost, vector<int> &dp)
    {
        if(n == 0)
            return cost[0];
        
        if(n == 1)
            return cost[1];
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = min(solve(n-1, cost, dp), solve(n-2, cost, dp)) + cost[n];
        return dp[n];
    }
    
    int solve2(int n, vector<int> &cost)
    {
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++)
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        
        return min(dp[n-1], dp[n-2]);
    }
    
    int solve3(int n, vector<int> &cost)
    {
        int p1 = cost[0];
        int p2 = cost[1];
        
        for(int i=2; i<n; i++)
        {
            int temp = min(p1, p2) + cost[i];
            p1 = p2;
            p2 = temp;
        }
        
        return min(p1, p2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
//         //step 1
//         vector<int> dp(n+1, -1);
        
//         int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
//         return ans;
        
        // return solve2(n, cost);
        return solve3(n, cost);
    }
};