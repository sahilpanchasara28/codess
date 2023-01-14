class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string b) {
        
        char mapping[26];
        
        for(int i=0; i<26; i++)
            mapping[i] = ('a' + i);
        
        for(int i=0; i<s1.size(); i++)
        {
            char maxChar = max(mapping[s1[i] - 'a'], mapping[s2[i] - 'a']);
            char minChar = min(mapping[s1[i] - 'a'], mapping[s2[i] - 'a']);
            
            for(int i=0; i<26; i++)
            {
                if(mapping[i] == maxChar)
                    mapping[i] = minChar;
            }
        }
        
        for(int i=0; i<b.size(); i++)
            b[i] = mapping[b[i] - 'a'];
        
        return b;
    }
};