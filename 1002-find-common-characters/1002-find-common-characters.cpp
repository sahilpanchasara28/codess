class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> m(26, INT_MAX);
        
        for(int i=0; i<words.size(); i++)    
        {
            vector<int> temp(26, 0);
            for(int j=0; j<words[i].size(); j++)
                temp[words[i][j] - 'a']++;
            
            for(int j=0; j<26; j++)
                m[j] = min(m[j], temp[j]);
        }
        
        vector<string> ans;
        
        for(int i=0; i<26; i++)
            while(m[i]--)
                ans.push_back(string(1, i + 'a'));
                
        return ans;
}
};