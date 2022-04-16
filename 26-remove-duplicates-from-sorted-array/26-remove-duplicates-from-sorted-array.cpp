class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int i=0, j=1;
        while(i < nums.size() && j < nums.size())
        {
            if(nums[i] == nums[j])
            {
                auto it = nums.begin()+i;
                nums.erase(it);
            }
            else
            {
                i++;
                j++;
            }
        }
        
        return nums.size();
    }
};