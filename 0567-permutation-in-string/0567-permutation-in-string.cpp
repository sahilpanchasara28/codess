class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size())
            return 0;
        
        vector<int> m1(26, 0), m2(26, 0);
    
        int i=0; 
        for(i=0; i<s1.size(); i++)
        {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }
        
        if(m1 == m2)
            return 1;
        
        for(; i<s2.size(); i++)
        {
            m2[s2[i-s1.size()] - 'a']--;
            m2[s2[i] - 'a']++;
            
            if(m1 == m2)
                return 1;
        }
        
        return 0;
    }
};