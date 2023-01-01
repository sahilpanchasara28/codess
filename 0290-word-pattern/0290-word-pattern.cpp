class Solution {
public:
    bool wordPattern(string pat, string s) {
        vector<string> v;
        string word; 
        stringstream iss(s); 
        while (iss >> word)
            v.push_back(word);
        
        if(pat.size() != v.size())
            return 0;
        
        map<char, string> m;
        
        for(int i=0; i<pat.size(); i++)
        {
            if(m.find(pat[i]) != m.end())
            {
                if(v[i] != m[pat[i]])
                    return 0;
            }
            else
                m[pat[i]] = v[i];
        }
        
        map<string, char> m1;
        
        for(int i=0; i<pat.size(); i++)
        {
            if(m1.find(v[i]) != m1.end())
            {
                if(pat[i] != m1[v[i]])
                    return 0;
            }
            else
                m1[v[i]] = pat[i];
        }
        
        return 1;
    }
};