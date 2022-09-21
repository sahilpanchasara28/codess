class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int sum = 0;
        
        for(int &i: nums)
            if(i%2 == 0)
                sum += i;
        
        for(int i=0; i<queries.size(); i++)
        {
            int val = queries[i][0];
            int ind = queries[i][1];
            
            if(nums[ind]%2 == 0)
                sum -= nums[ind];
            
            nums[ind] += val;
            
            if(nums[ind]%2 == 0)
                sum += nums[ind];
            
            ans[i] = sum;
        }
        
        return ans;
    }
};