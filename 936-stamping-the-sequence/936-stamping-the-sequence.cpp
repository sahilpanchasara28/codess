class Solution {
public:
    
    bool allChar(string &a)
    {
        for(int i=0; i<a.size(); i++)
            if(a[i] != '?')
                return 0;
        return 1;
    }
    
    bool match(string &a, string &b)
    {
        if(a.size() != b.size())
            return 0;
        
        for(int i=0; i<a.size(); i++)
            if(a[i] != b[i] && a[i] != '?' && b[i] != '?')
                return 0;
        return 1;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        bool check = true;
        int n = stamp.size(), m = target.size();
        vector<int> ans;
        
        while(check)
        {
            check = false;
            
            for(int i=0; i<m-n+1; i++)
            {
                string str = target.substr(i, n);
                
                if(allChar(str))
                    continue;
                
                if(match(str, stamp))
                {
                    check = true;
                    ans.push_back(i);
                    
                    for(int j=0; j<n; j++)
                        target[i+j] = '?';
                }
            }
        }
        
        if(!allChar(target))  ans.clear();
        if(ans.size() > 10*m) ans.clear();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};