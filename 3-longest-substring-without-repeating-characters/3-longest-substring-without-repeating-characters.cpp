class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int l = 0, r= 0;
        unordered_set<char> m;
        int ans = 0;
        
        while(r < n)
        {
            if(m.find(s[r]) != m.end())
            {
                m.erase(s[l]);
                l++;
            }
            else
            {
                m.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
            }
            
            
        }
        
        return ans;
    }
};