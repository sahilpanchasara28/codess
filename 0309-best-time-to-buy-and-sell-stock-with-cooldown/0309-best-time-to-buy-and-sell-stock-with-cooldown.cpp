class Solution {
    int recursiveMem(vector<int>&values, int n, int i, bool prevBought, vector<vector<int>> &dp)
{
    if(i >= n)
        return 0;
    
    if(dp[i][prevBought] != -1)
        return dp[i][prevBought];
        
    if(prevBought)
    {
        //can only sell
        
        int sell = recursiveMem(values, n, i+2, 0, dp) + values[i];
        int notSell = recursiveMem(values, n, i+1, 1, dp);
        return dp[i][prevBought] = max(sell, notSell);
    }
    else
    {
        //can only buy
        
        int buy = recursiveMem(values, n, i+1, 1, dp) - values[i];
        int notBuy = recursiveMem(values, n, i+1, 0, dp);
        return dp[i][prevBought] = max(buy, notBuy);
    }
}
    
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return recursiveMem(prices, n, 0, 0, dp);
    }
};