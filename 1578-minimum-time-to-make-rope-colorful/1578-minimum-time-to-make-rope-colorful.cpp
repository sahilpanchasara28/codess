class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int total = 0, maxi = 0, n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            if(i > 0 && colors[i] != colors[i-1])
                maxi = 0;
            
            total += min(maxi, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        
        return total;
    }
};