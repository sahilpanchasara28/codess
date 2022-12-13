class Solution {
    int timer = 1;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &time, vector<int> &low, vector<bool> &vis, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        
        for(auto neigh: adj[node])
        {
            if(neigh == parent)
                continue;
            
            if(!vis[neigh])
            {
                dfs(neigh, node, adj, time, low, vis, ans);
                low[node] = min(low[node], low[neigh]);
                
                // can this node --- neigh be a bridge
                
                if(time[node] < low[neigh])
                    ans.push_back({node, neigh});
            }
            else
                low[node] = min(low[node], low[neigh]);
        }
    }
    
    public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)     {
        vector<int> adj[n];
        
        for(auto i: connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> time(n);
        vector<int> low(n);
        vector<bool> vis(n, 0);
        vector<vector<int>> ans;
        
        dfs(0, -1, adj, time, low, vis, ans);
        return ans;
    }
};