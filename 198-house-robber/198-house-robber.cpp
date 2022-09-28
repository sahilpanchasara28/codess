class Solution {
public:
    int solve(vector<int> &nums, int ind, vector<int> &dp)
    {
        if(ind < 0)
            return 0;
        
        if(ind == 0)
            return nums[0];
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int take = nums[ind] + solve(nums, ind-2, dp);
        int notTake = solve(nums, ind-1, dp);
        
        return dp[ind] = max(take, notTake);
    }
    
    int solveTab(vector<int> &nums, int n)
    {
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        
        for(int i=1; i<n; i++)
        {
            int take = i-2 >=0 ? nums[i] + dp[i-2] : nums[i];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }  

        return dp[n-1];
    }
    
    int solveTabSpace(vector<int> &nums, int n)
    {
        
        
        int prev2 = 0, prev1 = nums[0];
        
        for(int i=1; i<n; i++)
        {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }  

        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
//         vector<int> dp(n, -1);
        
//         return solve(nums, n-1, dp);
        // return solveTab(nums, n);
        return solveTabSpace(nums, n);
    }
};