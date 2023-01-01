class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = nums.size(), elemXor = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            Xor ^= i;
            elemXor ^= nums[i];
        }
        
        return Xor ^ elemXor;
    }
};