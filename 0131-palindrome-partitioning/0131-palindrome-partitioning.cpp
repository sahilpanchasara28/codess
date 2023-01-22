class Solution {
public:
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start++] != s[end--])
                return 0;
        }
        
        return 1;
    }
    
    void solve(int ind, string s, vector<string>&temp, vector<vector<string>> &ans)
    {
        if(ind == s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind; i<s.size(); i++)
        {
            if(isPalindrome(s, ind, i))
            {
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(0, s, temp, ans);
        return ans;
    }
};