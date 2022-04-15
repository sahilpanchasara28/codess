class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int sum = 0, count = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            int rem = sum%k;
            
            if(rem < 0)
                rem += k;
            
            if(rem == 0)
                count++;
            
            if(m.find(rem) != m.end())
                count += m[rem];
            
            m[rem]++;
        }
        return count;
    }
};