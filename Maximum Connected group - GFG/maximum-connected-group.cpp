//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1, 0);

        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulp_u = findParent(u); // ultimate parent of u
        int ulp_v = findParent(v); // ultimate parent of v

        if(ulp_u == ulp_v) // already in same component then no need of union
            return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findParent(u); // ultimate parent of u
        int ulp_v = findParent(v); // ultimate parent of v

        if(ulp_u == ulp_v) // already in same component then no need of union
            return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int ans = -1e9;
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int ind=0; ind<4; ind++)
                    {
                        int row = i + dr[ind], col = j + dc[ind];
                        if(row>=0 and row<n and col>=0 and col<n and grid[row][col])
                            ds.UnionBySize(n*row + col, n*i + j);
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                {
                    int currSize = 1;
                    unordered_set<int> s;
                    for(int ind=0; ind<4; ind++)
                    {
                        int row = i + dr[ind], col = j + dc[ind];
                        if(row>=0 and row<n and col>=0 and col<n and grid[row][col])
                            s.insert(ds.findParent(n*row + col));
                    }
                    
                    for(auto q: s)
                        currSize += ds.size[q];
                        
                    ans = max(ans, currSize);
                }
            }
        }
        
        for(int i=0; i<=n*n; i++)
            ans = max(ans, ds.size[ds.findParent(i)]);

        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends