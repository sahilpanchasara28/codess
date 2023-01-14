class Solution {
public:
    
    char dfs(char node, unordered_map<char, string> &m, vector<bool> &vis)
    {
        vis[node - 'a'] = 1;
        
        char ans = node;
        for(auto neigh: m[node])
        {
            if(!vis[neigh - 'a'])
                ans = min(ans, dfs(neigh, m, vis));
        }
        
        return ans;
    }
    
    string smallestEquivalentString(string s1, string s2, string b) {
        unordered_map<char, string> m;
        
        for(int i=0; i<s1.size(); i++)
        {
            m[s1[i]].push_back(s2[i]);
            m[s2[i]].push_back(s1[i]);
        }
        
        
        
        for(int i=0; i<b.size(); i++)
        {
            vector<bool> vis(26, 0);
            b[i] = dfs(b[i], m, vis);
        }
        
        return b;
    }
};