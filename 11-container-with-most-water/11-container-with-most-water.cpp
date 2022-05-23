class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size(), maxarea = 0;
        int left = 0, right = n-1;
        
        while(left < right)
        {
            int width = min(height[left], height[right]);
            int length = right - left;
            maxarea = max(maxarea, width * length);
            
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
            
        return maxarea;
    }
};