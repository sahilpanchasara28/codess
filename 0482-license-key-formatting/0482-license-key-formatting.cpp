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
        string temp = "";
        
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '-')
                continue;
            
            if(temp.size() == k)
            {
                temp.push_back('-');
                ans += temp;
                temp = "";
            }
        
            temp.push_back(to_upper(s[i]));
        }
        
        if(temp.size() > 0)
            ans += temp;
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};