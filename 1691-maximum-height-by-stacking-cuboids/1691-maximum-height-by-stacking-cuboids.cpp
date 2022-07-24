class Solution {
public:
    
    bool Check(vector<int> &base, vector<int> &top)
    {
        if(top[0] <= base[0] && top[1] <= base[1] && top[2] <= base[2])
            return true;
        else
            return false;
    }
    
    int LIS(vector<vector<int>>& nums, int n)
    {
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int prev=ind-1; prev>=-1; prev--)
            {
                int include = 0;
                if(prev == -1 || Check(nums[ind], nums[prev]))
                    include = nums[ind][2] + next[ind+1];
                
                int exclude = next[prev+1];
                
                curr[prev+1] = max(include, exclude);
            }
            next = curr;
        }
        
        return next[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto &a: cuboids)
            sort(a.begin(), a.end());
        
        sort(cuboids.begin(), cuboids.end());
        
        return LIS(cuboids, cuboids.size());
    }
};