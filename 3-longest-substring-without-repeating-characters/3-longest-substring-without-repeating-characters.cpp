class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        unordered_map<char, int> m;
        
        int l = 0, r = 0, ans = 0;
        
        for(int r=0; r<str.size(); r++)
        {
            if(m[str[r]])
                l = max(l, m[str[r]]);
            
            m[str[r]] = r+1;
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};