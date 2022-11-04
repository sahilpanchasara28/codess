class Solution {
public:
    string reverseVowels(string s) {
        
        int i=0, j=s.size()-1;
        unordered_map<char, bool> vowel;
        
        vowel['a'] = 1;
        vowel['e'] = 1;
        vowel['i'] = 1;
        vowel['o'] = 1;
        vowel['u'] = 1;
        vowel['A'] = 1;
        vowel['E'] = 1;
        vowel['I'] = 1;
        vowel['O'] = 1;
        vowel['U'] = 1;
        
        while(i<j)
        {
            if(vowel[s[i]] and vowel[s[j]])
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            
            while(i<j and !vowel[s[i]])
                i++;
            
            while(i<j and !vowel[s[j]])
                j--;
        }
        
        return s;
    }
};