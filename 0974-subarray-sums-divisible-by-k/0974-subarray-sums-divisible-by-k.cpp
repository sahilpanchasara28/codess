class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
           
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            int rem = sum%k;
            
            if(rem < 0)
                rem += k;
            
            if(rem == 0)
                ans++;
            
            if(m.find(rem) != m.end())
                ans += m[rem];
            
            m[rem]++;
        }
        
        return ans;
    }
};