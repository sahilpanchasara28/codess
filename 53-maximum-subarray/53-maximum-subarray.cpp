class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        
        int maxSum = INT_MIN, sum = 0, n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            
            if(maxSum < sum)
                maxSum = sum;
                
            if(sum < 0)
                sum = 0;
        }
        

        return maxSum;
        
    }
};