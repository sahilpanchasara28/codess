class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, n = nums.size();
        m[0] = -1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            
            if(m.find(sum%k) != m.end())
            {
                if(i - m[sum%k] >= 2)
                    return true;
            }
            else
                m[sum%k] = i;   
        }
        return false;
    }
};