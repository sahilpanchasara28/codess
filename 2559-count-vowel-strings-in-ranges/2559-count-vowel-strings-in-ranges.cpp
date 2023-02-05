class Solution {
public:
    
    bool isVowel(char c)
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> pre;
        pre.push_back(0);
        
        for(auto i: words)
            pre.push_back(pre.back() + (isVowel(i[0]) and isVowel(i.back())));
        
     
        vector<int> ans;
        
        for(auto q: queries) 
            ans.push_back(pre[q[1]+1] - pre[q[0]]);
        
        return ans;
    }
};