class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-1;
        int count = 0, ans = -1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            count = 0;
            for(int i: nums)
                if(i <= mid)
                    count++;
            
            if(count > mid)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return ans;
    }
};