class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] % 2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        
        int curr_sum = 0, ans = 0;
        unordered_map<int, int> m;
        
        m[0] = 1;
        for(int i=0; i<n; i++)
        {
            curr_sum += nums[i];
            
            if(m.find(curr_sum-k) != m.end())
                ans += m[curr_sum-k];
            
            m[curr_sum]++;
        }
        
        return ans;
    }
};