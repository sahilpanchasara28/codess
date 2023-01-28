class Solution {
public:
    
    void firstBS(vector<int>& nums, int t, int &ans)
    {
        int s = 0, e = nums.size()-1;
        
        while(s <= e)
        {
            int mid = (s+e)/2;
            
            if(nums[mid] == t)
            {
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < t)
                s = mid+1;
            else
                e = mid-1;
        }
    }
    
    void lastBS(vector<int>& nums, int t, int &ans)
    {
        int s = 0, e = nums.size()-1;
        
        while(s <= e)
        {
            int mid = (s+e)/2;
            
            if(nums[mid] == t)
            {
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < t)
                s = mid+1;
            else
                e = mid-1;
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        
        int s = -1, e = -1;
        firstBS(nums, t, s);
        lastBS(nums, t, e);
        
        return {s, e};
    }
};