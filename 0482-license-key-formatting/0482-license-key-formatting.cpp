class Solution {
public:
    
    char to_upper(char c)
    {
        if(c >= 'a' and c <= 'z')
            return c-32;
        
        return c;
    }
    
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int c = 0;
        
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '-')
                continue;
            
            ans.push_back(to_upper(s[i]));
            c++;
            
            if(c == k)
            {
                ans.push_back('-');
                c = 0;
            }
        }
        
        if(ans.size() > 0 and ans.back() == '-')
            ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};