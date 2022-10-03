class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int total = 0;
        int s = 0, e = 0, n = colors.size();
        
        while(s < n && e < n)
        {
            int curr = 0, maxi = 0;
            while(e < n && colors[s] == colors[e])
            {
                curr += arr[e];
                maxi = max(maxi, arr[e]);
                e++;
            }
            
            total += (curr - maxi);
            s = e;
        }
        
        return total;
    }
};