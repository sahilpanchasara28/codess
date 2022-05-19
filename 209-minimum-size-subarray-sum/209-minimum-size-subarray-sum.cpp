class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start = 0, end, n = nums.size();
        int sum = 0, ans = INT_MAX;
        
        for(end = 0; end < n; end++)
        {
                sum += nums[end];
                
            while(sum >= target)
            {
                ans = min(ans, end-start+1);
                sum -= nums[start];
                start++;
            }
        }
        if(ans == INT_MAX)  return 0;
        return ans;
    }
};