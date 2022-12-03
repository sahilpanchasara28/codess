class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
         for(auto c : s)
        m[c]++;
    vector<pair<int, char>> v;
    for(auto it : m)
        v.push_back({it.second, it.first});
    sort(v.begin(), v.end(), [](pair<int, char> a, pair<int, char> b){return a.first > b.first;});
    string res = "";
    for(auto it : v)
        res += string(it.first, it.second);
    return res;
        
    }
};