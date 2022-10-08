class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int minDiff = 1e9, ans = 0;
        
        for(int i=0; i<n-2; i++)
        {
            int l = i+1, r = n-1;
            
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                int diff = abs(target - sum);
                
                if(diff < minDiff)
                {
                    ans = sum;
                    minDiff = diff;
                }
                
                if(sum < target)
                    l++;
                else
                    r--;
            }
        }
        
        return ans;
    }
};