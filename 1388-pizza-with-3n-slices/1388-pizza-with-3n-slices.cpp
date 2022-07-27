class Solution {
public:
    
    int solve(vector<int> &arr, int ind, int endInd, int n)
    {
        if(n == 0 || ind > endInd)
            return 0;
        
        int include = arr[ind] + solve(arr, ind+2, endInd, n-1);
        int exclude = solve(arr, ind+1, endInd, n);
        
        return max(include, exclude);
    }
    
    int solveMem(vector<int> &arr, int ind, int endInd, int sliceLeft, vector<vector<int>> &dp)
    {
        if(sliceLeft == 0 || ind > endInd)
            return 0;
        
        if(dp[ind][sliceLeft] != -1)
            return dp[ind][sliceLeft];
        
        int include = arr[ind] + solveMem(arr, ind+2, endInd, sliceLeft-1, dp);
        int exclude = solveMem(arr, ind+1, endInd, sliceLeft, dp);
        
        return dp[ind][sliceLeft] = max(include, exclude);
    }
    
    int tabulation(vector<int> &arr)
    {
        int k = arr.size();
        
        vector<vector<int>> dp1(k+2, vector<int> (k/3 +1, 0));
        
        for(int ind = k-2; ind >= 0; ind--)
        {
            for(int sliceLeft = 1; sliceLeft <= k/3; sliceLeft++)
            {
                int include = arr[ind] + dp1[ind+2][sliceLeft-1];
                int exclude = dp1[ind+1][sliceLeft];

                dp1[ind][sliceLeft] = max(include, exclude);
            }
        }
        
        int ans1 = dp1[0][k/3];
        
        vector<vector<int>> dp2(k+2, vector<int> (k/3 +1, 0));
        
        for(int ind = k-1; ind >= 1; ind--)
        {
            for(int sliceLeft = 1; sliceLeft <= k/3; sliceLeft++)
            {
                int include = arr[ind] + dp2[ind+2][sliceLeft-1];
                int exclude = dp2[ind+1][sliceLeft];

                dp2[ind][sliceLeft] = max(include, exclude);
            }
        }
        
        int ans2 = dp2[1][k/3];
        
        return max(ans1, ans2);
    }
    
    int spaceOptimised(vector<int> &arr)
    {
        int k = arr.size();
        
        vector<int> prev1(k/3 + 1, 0);
        vector<int> curr1(k/3 + 1, 0);
        vector<int> next1(k/3 + 1, 0);
        
        for(int ind = k-2; ind >= 0; ind--)
        {
            for(int sliceLeft = 1; sliceLeft <= k/3; sliceLeft++)
            {
                int include = arr[ind] + next1[sliceLeft-1];
                int exclude = curr1[sliceLeft];

                prev1[sliceLeft] = max(include, exclude);
            }
            
            next1 = curr1;
            curr1 = prev1;
        }
        
        int ans1 = curr1[k/3];
        
        vector<int> prev2(k/3 + 1, 0);
        vector<int> curr2(k/3 + 1, 0);
        vector<int> next2(k/3 + 1, 0);
        
        for(int ind = k-1; ind >= 1; ind--)
        {
            for(int sliceLeft = 1; sliceLeft <= k/3; sliceLeft++)
            {
                int include = arr[ind] + next2[sliceLeft-1];
                int exclude = curr2[sliceLeft];

                prev2[sliceLeft] = max(include, exclude);
            }
            
            next2 = curr2;
            curr2 = prev2;
        }
        
        int ans2 = curr2[k/3];
        
        return max(ans1, ans2);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        
//         int ans1 = solve(slices, 0, k-2, k/3);
//         int ans2 = solve(slices, 1, k-2, k/3);
        
//         return max(ans1, ans2);
        
        
//         vector<vector<int>> dp1(k+1, vector<int> (k/3 +1, -1));
//         int ans1 = solveMem(slices, 0, k-2, k/3, dp1);
        
//         vector<vector<int>> dp2(k+1, vector<int> (k/3 +1, -1));
//         int ans2 = solveMem(slices, 1, k-1, k/3, dp2);

//         return max(ans1, ans2);
        
        // return tabulation(slices);
        
        return spaceOptimised(slices);
    }
};