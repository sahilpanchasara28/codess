class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int start = 0, end = 0, n = s.size(), ans = 0;
        unordered_map<char, int> m;
        
        while(end < n)
        {
            m[s[end]]++;
            end++;
            
            while(m.size() >= 3)
            {
                m[s[start]]--;
                if(m[s[start]] == 0)
                    m.erase(s[start]);
                
                start++;
                ans += (n-end+1);
            }
        }
        return ans;
    }
};