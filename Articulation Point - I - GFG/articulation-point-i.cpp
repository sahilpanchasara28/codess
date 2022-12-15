//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  
    int timer = 0;
    
    void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis, vector<int> &tim, vector<int> &low, vector<bool> &mark)
    {
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        
        int unVisChild = 0; // doing for root node
        
        for(auto neigh: adj[node])
        {
            if(neigh == parent)
                continue;
            
            if(!vis[neigh])
            {
                dfs(neigh, node, adj, vis, tim, low, mark);
                low[node] = min(low[node], low[neigh]);
                
                // check if node is articulation point or not
                if(parent != -1 and low[neigh] >= tim[node])
                    mark[node] = 1;
                    
                unVisChild++;
            }
            else
            {
                // neigh already visited, so take it's time point
                low[node] = min(low[node], tim[neigh]);
            }
        }
        
        // articulation point condition for root node
        if(parent == -1 and unVisChild > 1)
            mark[node] = 1;
    }
  
    public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        
        vector<bool> vis(n, 0);
        vector<int> tim(n);
        vector<int> low(n);
        vector<bool> mark(n, 0);
        
        for(int node=0; node<n; node++)
        {
            if(!vis[node])
                dfs(node, -1, adj, vis, tim, low, mark);
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if(mark[i])
                ans.push_back(i);
        }
        
        if(ans.empty())
            return {-1};
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends