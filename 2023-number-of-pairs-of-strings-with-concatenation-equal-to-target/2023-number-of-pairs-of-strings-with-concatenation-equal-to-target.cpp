class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans = 0;
        int n = nums.size();
        unordered_map<string, int> m;
        
        for(int i=0; i<n; i++)
            m[nums[i]]++;
        
        for(int i=0; i<n; i++)
        {
            
            if(target.substr(0, nums[i].size()) == nums[i])
            {
                string rem = target.substr(nums[i].size());
                ans += m[rem];
                
                if(rem == nums[i])
                    ans--;
            }
        }
        
        return ans;
    }
};