class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char, int>m1, m2;
        
        for(auto i: a)
            m1[i]++;
        
        for(auto i: b)
            m2[i]++;
        
        for(auto i: m1)
        {
            if(m2[i.first] < i.second)
                return false;
        }
        return true;
    }
};