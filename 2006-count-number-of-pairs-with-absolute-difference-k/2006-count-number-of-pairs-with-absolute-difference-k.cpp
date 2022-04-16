class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
     
        unordered_map<int, int> m;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int e1 = nums[i]+k;
            int e2 = nums[i]-k;
            
            if(m.find(e1) != m.end())
                count += m[e1];
            
            if(m.find(e2) != m.end())
                count += m[e2];
            
            m[nums[i]]++;
        }
        return count;
    }
};