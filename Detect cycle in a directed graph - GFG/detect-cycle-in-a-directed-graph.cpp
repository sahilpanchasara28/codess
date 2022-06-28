// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[])
    {
        visited[node] = dfsVisited[node] = true;
        
        for(auto nbr: adj[node])
        {
            if(visited[nbr] && dfsVisited[nbr])
                return true;
            else if(!visited[nbr])
            {
                bool ans = dfs(nbr, visited, dfsVisited, adj);
                if(ans)
                    return true;
            }
        }
        
        dfsVisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int i=0; i<V; i++)
            if(!visited[i])
            {
              bool ans = dfs(i, visited, dfsVisited, adj);
              if(ans)
                return true;
            }
                
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends