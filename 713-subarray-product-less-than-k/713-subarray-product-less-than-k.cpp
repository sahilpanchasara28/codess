class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int s = 0, e = 0, count = 0, prod = nums[0];
        int n = nums.size();
        
        while(s< n && e < n)
        {
            if(prod < k)
            {
                e++;
                if(e >= s)
                    count += e-s;
                
                if(e < n)
                    prod *= nums[e];
            }
            else
                prod /= nums[s++];
        }
        return count;
    }
};