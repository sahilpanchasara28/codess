class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxSum = -1e9, minSum = 1e9;
        int currSum1 = 0, currSum2 = 0, tot = 0;
        
        for(auto i: nums)
        {
            tot += i;
            currSum1 += i;
            currSum2 += i;
            
            maxSum = max(maxSum, currSum1);
            if(currSum1 < 0)
                currSum1 = 0;
            
            minSum = min(minSum, currSum2);
            if(currSum2 > 0)
                currSum2 = 0;
        }
        
        if(tot == minSum)
            return maxSum;
        
        return max(maxSum, tot-minSum);
    }
};