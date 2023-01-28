class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0, leftSum = 0;
        
        for(auto i: nums)
            totSum += i;
        
        for(int i=0; i<n; i++)
        {
            if(leftSum == totSum - leftSum - nums[i])
                return i;
            
            leftSum += nums[i];
        }
        
        return -1;
    }
};