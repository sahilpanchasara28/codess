class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        
        for(auto i: word)
        {
            if(i >= 'A' and i <= 'Z')
                capCount++;
        }
        
        if(capCount == 0 or capCount == word.size() or (capCount == 1 and word[0] >= 'A' and word[0] <= 'Z'))
            return true;
        
        return false;
    }
};