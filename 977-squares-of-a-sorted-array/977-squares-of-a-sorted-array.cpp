class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int i=0, j=n-1, curr=n-1;
        
        while(i <= j)
        {
            if(abs(nums[i]) < abs(nums[j]))
            {
                ans[curr--] = nums[j]*nums[j];
                j--;
            }
            else
            {
                ans[curr--] = nums[i]*nums[i];
                i++;
            }
        }
        
        return ans;
    }
};