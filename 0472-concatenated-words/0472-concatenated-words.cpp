class Solution {
public:
    
    bool solve(unordered_map<string, int>& m, string &word)
    {
        for(int i=1; i<word.size(); i++)
        {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            
            if(m[prefix] and (m[suffix] or solve(m, suffix)))
                return true;
        }
        
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        unordered_map<string, int> m;
        
        for(auto i: words)
            m[i]++;
        
        vector<string> ans;
        
        for(auto word: words)
        {
            if(solve(m, word))
                ans.push_back(word);
        }
    
        return ans;
    }
};