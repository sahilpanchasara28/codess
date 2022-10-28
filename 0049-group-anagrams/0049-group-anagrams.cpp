class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.size() == 1 and strs[0].size() == 0)
            return {{""}};
        
        unordered_map<string, vector<string>> m;
        
        for(auto s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for(auto i: m)
            ans.push_back(i.second);
        
        return ans;
    }
};