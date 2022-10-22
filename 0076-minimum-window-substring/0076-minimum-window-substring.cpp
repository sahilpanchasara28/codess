class Solution {
    bool isThere(const vector<int>& m) {
        return all_of(m.begin(), m.end(), [](int i) { return i <= 0; });
    }
public:
    
    string minWindow(string s, string t) {
        
        int n1 = s.size(), n2 = t.size();
        
        if(n2 > n1)
            return "";
        
        vector<int> m(128, 0);
        
        for (auto c : t)
            m[c]++;
        
        int l = 0, r = 0, ind1 = -1, len = 1e9;
        
        while(r < n1)
        {
            if(isThere(m))
            {
                if(r-l < len)
                {
                    len = r-l;
                    ind1 = l;
                }
                
                m[s[l]]++;
                l++;
            }
            else
            {
                m[s[r]]--;
                r++;
            }
        }
        
        while(isThere(m))
        {
  
            if(r-l < len)
            {
                len = r-l;
                ind1 = l;
            }

            m[s[l]]++;
            l++;
        }
        
        if (ind1 != -1) 
            return s.substr(ind1, len);
        
        return "";
    }
};