class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int,int> m;
        for(auto i:arr)
            m[i]++;
        
        set<int>s;
        for(auto i:m)
            s.insert(i.second);
        
        return s.size() == m.size();
    }
};