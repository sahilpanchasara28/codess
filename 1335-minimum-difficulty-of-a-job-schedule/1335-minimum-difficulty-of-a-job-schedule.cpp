class Solution {
public:
    
    int solve(int i, vector<int>& arr, int d, vector<vector<int>> &dp)
    {
        if(i == arr.size())
        {
            if(d == 0)
                return 0;
            else
                return 1e9;
        }
        
        if(d < 0)
            return 1e9;
        
        if(dp[i][d] != -1)
            return dp[i][d];
        
        int maxi = -1e9, ans = 1e9;
        for(int j=i; j<arr.size(); j++)
        {
            maxi = max(maxi, arr[j]);
            
            ans = min(ans, maxi+ solve(j+1, arr, d-1, dp));
        }
        
        return dp[i][d] = ans;
    }
    
    
    int minDifficulty(vector<int>& arr, int d) {
        int  n = arr.size();
        vector<vector<int>> dp(n, vector<int> (d+1, -1));
        
        if(n < d)
            return -1;
        
        int ans = solve(0, arr, d, dp);
        if(ans >= 1e9)
            return -1;
        
        return ans;
    }
};