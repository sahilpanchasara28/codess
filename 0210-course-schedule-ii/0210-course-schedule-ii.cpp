class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
	    
	    for(auto p: prerequisites)
	        adj[p[1]].push_back(p[0]);
	    
	    vector<int> indegree(V, 0);
        
        for(int i=0; i<V; i++)
        {
            for(auto neigh: adj[i])
                indegree[neigh]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        vector<int> ans;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto neigh: adj[front])
            {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        if(ans.size() == V)
            return ans;
        return {};
    }
};