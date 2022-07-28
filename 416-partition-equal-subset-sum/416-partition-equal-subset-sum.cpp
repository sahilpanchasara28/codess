class Solution {
public:
    
    bool recursive(vector<int>& arr, int ind, int n, int tar)
    {
        if(tar < 0)
            return 0;
            
        if(ind >= n)
            return 0;
        
        if(tar == 0)
            return 1;
        
        bool include = recursive(arr, ind+1, n, tar-arr[ind]);
        bool exclude = recursive(arr, ind+1, n, tar);
        
        return include or exclude;
    }
    
    bool recursiveMem(vector<int>& arr, int ind, int n, int tar, vector<vector<int>> &dp)
    {
        if(tar < 0)
            return 0;
            
        if(ind >= n)
            return 0;
        
        if(tar == 0)
            return 1;
            
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        bool include = recursiveMem(arr, ind+1, n, tar-arr[ind], dp);
        bool exclude = recursiveMem(arr, ind+1, n, tar, dp);
        
        return dp[ind][tar] = include or exclude;
    }
    
    bool tabulation(vector<int>& arr, int ind, int n, int target)
    {
        vector<vector<bool>> dp(n+1, vector<bool> (target+1, 0));
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int tar=1; tar<=target; tar++)
            {
                bool include = 0;
                if(tar-arr[ind] >= 0)
                    include = dp[ind+1][tar-arr[ind]];
                bool exclude = dp[ind+1][tar];
                
                dp[ind][tar] = include or exclude;
            }
        }
        
        return dp[0][target];
    }
    
    bool spaceOptimised(vector<int>& arr, int ind, int n, int target)
    {
        vector<bool> curr(target+1, 0);
        vector<bool> next(target+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int tar=1; tar<=target; tar++)
            {
                bool include = 0;
                if(tar-arr[ind] >= 0)
                    include = next[tar-arr[ind]];
                bool exclude = next[tar];
                
                curr[tar] = include or exclude;
            }
            next = curr;
        }
        
        return next[target];
    }
    
    bool canPartition(vector<int>& arr) {
        int sum = 0, N = arr.size();
        
        for(int i=0; i<N; i++)
            sum += arr[i];
        
        if(sum & 1)
            return 0;
        
        int tar = sum/2;
        
        
        // return recursive(arr, 0, N, tar);
        
        // vector<vector<int>> dp(N, vector<int> (tar+1, -1));
        // return recursiveMem(arr, 0, N, tar, dp);
        
        // return tabulation(arr, 0, N, tar);
        
        return spaceOptimised(arr, 0, N, tar);
    }
};