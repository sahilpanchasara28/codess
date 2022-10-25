class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> adj[n];
        int mod = 1e9+7;
        
        for(auto i: roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        priority_queue<pair<long long, long long>,
        vector<pair<long long, long long>>,
        greater<pair<long long, long long>>
        > minHeap;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        minHeap.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while(!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            
            long long d = top.first;
            long long u = top.second;
            
            for(auto neigh: adj[u])
            {
                long long v = neigh[0], w = neigh[1];
                if(d+w < dist[v])
                {
                    dist[v] = d+w;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                }
                else if(d+w == dist[v])
                    ways[v] = (ways[v] + ways[u])%mod;
            }
        }
        
        return ways[n-1]%mod;
    }
};