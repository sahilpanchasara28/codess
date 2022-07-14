class Solution {
public:
    int nthUglyNumber(int n) {
       
        vector<int> dp(n);
        dp[0] = 1;
        
        int ind1 = 0, ind2 = 0, ind3 = 0;
        
        for(int i=1; i<n; i++)
        {
            dp[i] = min({dp[ind1]*2, dp[ind2]*3, dp[ind3]*5});
            if(dp[i] == dp[ind1]*2) ind1++;
            if(dp[i] == dp[ind2]*3) ind2++;
            if(dp[i] == dp[ind3]*5) ind3++;
        }
        return dp[n-1];
    }
};