class Solution {
public:
    
    int recursive(int i, vector<int> &arr, int k, bool isPrevBought)
    {
        if(i >= arr.size() || k == 0)
            return 0;
        
        
        if(isPrevBought)
        {
            //can only sell
            int op1 = recursive(i+1, arr, k-1, 0) + arr[i]; //sell
            int op2 = recursive(i+1, arr, k, 1); // not sell
            return max(op1, op2);
        }
        else
        {
            //can only buy
            int op1 = recursive(i+1, arr, k, 1) - arr[i]; //buy
            int op2 = recursive(i+1, arr, k, 0); // not buy
            return max(op1, op2);
        }
    }
    
    int recursiveMem(int i, vector<int> &arr, int k, int trans, vector<vector<int>> &dp)
    {
        if(i >= arr.size() || trans == 2*k)
            return 0;
        
        if(dp[i][trans] != -1)
            return dp[i][trans];
        
        if(trans & 1)
        {
            //can only sell
            int op1 = recursiveMem(i+1, arr, k, trans+1, dp) + arr[i]; //sell
            int op2 = recursiveMem(i+1, arr, k, trans, dp); // not sell
            return dp[i][trans] = max(op1, op2);
        }
        else
        {
            //can only buy
            int op1 = recursiveMem(i+1, arr, k, trans+1, dp) - arr[i]; //buy
            int op2 = recursiveMem(i+1, arr, k, trans, dp); // not buy
            return dp[i][trans] = max(op1, op2);
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        // return recursive(0, prices, k, 0);
        
        vector<vector<int>> dp(prices.size(), vector<int> (2*k, -1));
        return recursiveMem(0, prices, k, 0, dp);
    }
};