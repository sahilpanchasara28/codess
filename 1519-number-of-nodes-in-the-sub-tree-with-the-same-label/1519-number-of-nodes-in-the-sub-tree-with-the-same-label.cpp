class Solution {
public:
    
    vector<int> solve(int node, int par, int n, vector<int> adj[], string &s, vector<int> &ans) {
        
        vector<int> hash(26, 0);
        hash[s[node] - 'a'] = 1;
        
        for(auto child: adj[node])
        {
            if(child != par)
            {
                vector<int> temp = solve(child, node, n, adj, s, ans);
                
                for(int i=0; i<26; i++)
                    hash[i] += temp[i];
            }
        }
        
        ans[node] = hash[s[node] - 'a'];
        return hash;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        
        vector<int> adj[n];
        vector<int> ans(n, 0);
                
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> hash = solve(0, -1, n, adj, s, ans);
        
        return ans;
    }
};