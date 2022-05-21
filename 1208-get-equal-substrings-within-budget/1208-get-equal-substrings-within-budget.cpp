class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int start = 0, end = 0, ans = 0;
        int n = s.size(), curr_cost = 0;
        
        while(end < n)
        {
            while(curr_cost > maxCost)
            {
                curr_cost -= abs(s[start] - t[start]);
                start++;
            }
            
            curr_cost += abs(s[end] - t[end]);
            
            if(curr_cost <= maxCost)
                ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};