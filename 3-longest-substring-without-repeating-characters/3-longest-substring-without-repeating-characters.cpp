class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        unordered_map<char, int> m;
        
        int l = 0, r = 0, ans = 0;
        
        while(r < str.size())
        {
            m[str[r]]++;
            
            while(m[str[r]] > 1)
            {
                m[str[l]]--;
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};