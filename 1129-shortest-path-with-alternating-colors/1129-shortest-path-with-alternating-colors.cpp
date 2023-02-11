class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto i: redEdges)
            adj[i[0]].push_back({i[1], 0});
        
        for(auto i: blueEdges)
            adj[i[0]].push_back({i[1], 1});
        
        vector<int> ans(n, -1);
        
        vector<vector<bool>> vis(n, vector<bool> (2, 0));
        
        queue<vector<int>> q;
        
        q.push({0, 0, -1});
        vis[0][0] = vis[0][1] = 1;
        ans[0] = 0;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            int node = front[0], steps = front[1], prevColor = front[2];
            
            for(auto& [neigh, color]: adj[node])
            {
                if(!vis[neigh][color] and color != prevColor)
                {
                    vis[neigh][color] = 1;
                    q.push({neigh, 1+steps, color});
                    
                    if(ans[neigh] == -1)
                        ans[neigh] = 1 + steps;
                        
                }
            }
        }
        
        return ans;
    }
};