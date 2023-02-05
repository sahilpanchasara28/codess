class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ind;
        
        if(p.size() > s.size())
            return ind;
        
        vector<int> m1(26, 0), m2(26, 0);
        int i=0;
        
        for(i=0; i<p.size(); i++)
        {
            m1[p[i] - 'a']++;
            m2[s[i] - 'a']++;
        }
        
        if(m1 == m2)
            ind.push_back(0);
        
        for(; i<s.size(); i++)
        {
            m2[s[i] - 'a']++;
            m2[s[i - p.size()] - 'a']--;
            
            if(m1 == m2)
                ind.push_back(i - p.size()+1);
        }
        
        return ind;
    }
};