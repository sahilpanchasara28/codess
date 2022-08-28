class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> preSum(n, 0);
        
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + nums[i];
        
        vector<int> ans;
        for(auto i: q)
        {
            int ind = upper_bound(preSum.begin(), preSum.end(), i) - preSum.begin();
            ans.push_back(ind);
        }
        
        return ans;
    }
};