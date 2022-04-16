class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size(), count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(m.find(k-nums[i]) != m.end() && m[k-nums[i]] > 0)
            {
                count++;
                m[k-nums[i]]--;
                m[nums[i]]--;
            }
            
            m[nums[i]]++;
        }
        return count;
    }
};