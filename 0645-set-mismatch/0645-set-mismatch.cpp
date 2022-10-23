class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp)
            if(it.second==2)
                ans.push_back(it.first);
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};