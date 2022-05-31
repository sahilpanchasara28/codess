class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int i: nums)
            ans += i-nums[0];
        
        return ans;
    }
};