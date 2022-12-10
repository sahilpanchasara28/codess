//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    
    void dfs(int node, vector<bool> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
                dfs(neigh, vis, adj, st);
        }
        
        st.push(node);
    }
    
    void dfs3(int node, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for(auto neigh: adj[node])
        {
            if(!vis[neigh])
                dfs3(neigh, vis, adj);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph
    
    int kosaraju(int V, vector<int> adj[])
    {
        // step 1: sort the graph in finishing time i.e. stack
        vector<bool> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
                dfs(i, vis, adj, st);
        }
        
        // step 2: reverse the graph
        vector<int> revAdj[V];
        
        for(int i=0; i<V; i++)
        {
            vis[i] = 0;
            for(auto it: adj[i])
            {
                // i -> it is the original edge
                // so do it -> i 
                revAdj[it].push_back(i);
            }
        }
        
        // step 3: Do dfs from taking vertexes from stack
        int scc = 0;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(!vis[top])
            {
                scc++;
                dfs3(top, vis, revAdj);
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends