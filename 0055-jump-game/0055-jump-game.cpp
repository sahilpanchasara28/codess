class Solution {
public:
    
    bool solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if(i == nums.size()-1)
            return true;
        
        if(i >= nums.size())
            return false;
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int ind=i+1; ind<=i+nums[i]; ind++)
        {
            bool ans = solve(nums, ind, dp);
            if(ans)
                return dp[i] = true;
        }
        
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};