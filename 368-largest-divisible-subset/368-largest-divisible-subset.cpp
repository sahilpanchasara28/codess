class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = -1e9, maxInd = 0;
        
        for(int i=0; i<n; i++)
        {
            hash[i] = i;
            for(int prev=0; prev<i; prev++)
            {
                if(arr[i]%arr[prev] == 0 && 1+dp[prev] > dp[i])
                {
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                maxInd = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[maxInd]);
        
        while(maxInd != hash[maxInd])
        {
            maxInd = hash[maxInd];
            ans.push_back(arr[maxInd]);
        }
        
        return ans;
    }
};