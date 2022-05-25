class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, element = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            if(vote == 0)
                element = nums[i];
            
            if(nums[i] == element)
                vote++;
            else
                vote--;
        }
        
        return element;
    }
};