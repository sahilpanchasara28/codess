class Solution {
public:
    
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0] != b[0]) return a[0] < b[0];
        
        return a[1] > b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& env) {
        
        sort(env.begin(), env.end(), cmp);
 
        vector<int> ans;
        ans.push_back(env[0][1]);
        int n = env.size();
        
        for(int i=1; i<n; i++)
        {
            if(env[i][1] > ans.back())
                ans.push_back(env[i][1]);
            else
            {
                int ind = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[ind] = env[i][1];
            }
        }
        
        return ans.size();
    }
};