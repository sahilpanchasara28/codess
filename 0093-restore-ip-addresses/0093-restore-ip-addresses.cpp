class Solution {
public:
    
    void solve(int i, string s, string res, string curr, vector<string> &ans)
    {
        if(i == s.size())
        {
            if(curr.empty() and count(res.begin(),res.end(),'.')==3)
                ans.push_back(res);
                
            return;
        }
        
        if(!curr.empty() and stoi(curr) == 0)
            return;
        
        curr.push_back(s[i]);
        
        if(stoi(curr) > 255)
            return;
        
        solve(i+1, s, res, curr, ans);
        
        if(!res.empty())
            solve(i+1, s, res+"."+curr, "", ans);
        else
            solve(i+1, s, curr, "", ans);
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr = "";
        string res = "";
        
        if(s.size() >= 4 and s.size() <= 12)
            solve(0, s, res, curr, ans);
        
        return ans;
    }
};