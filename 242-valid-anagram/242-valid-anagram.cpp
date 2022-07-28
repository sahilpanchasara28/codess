class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        
        unordered_map<char, int> m1, m2;
        for(char i: s)
            m1[i]++;
        for(char i: t)
            m2[i]++;
        
        for(auto i: s)
            if(m1[i] != m2[i])
                return false;
        return true;
    }
};