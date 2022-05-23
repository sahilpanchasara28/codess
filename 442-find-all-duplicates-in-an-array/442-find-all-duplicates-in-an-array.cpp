class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(auto i: nums)
        {
            int curr = abs(i);
            if(nums[curr-1] < 0)
                ans.push_back(curr);
            else
                nums[curr-1] *= -1;
        }
        return ans;
    }
};