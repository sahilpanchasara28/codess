class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) 
            {
                int curr = nums[i];
                int left = i+1, right = n-1;

                while(left < right)
                {
                    if(curr + nums[left] + nums[right] == 0)
                    {
                        vector<int> temp;
                        temp.push_back(curr);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        while(left < right && nums[right] == nums[right-1])
                            right--;
                        
                        left++;
                        right--;
                    }
                    else if(curr + nums[left] + nums[right] > 0)
                        right--;
                    else
                        left++;
                }
            }
        }
        
        return ans;
    }
};