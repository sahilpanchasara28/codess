//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    vector<int> rank, size, parent;

    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DisjointSet ds(n*m);
        vector<int> ans;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int count = 0;
        for(auto op: operators)
        {
            int r = op[0], c = op[1];
            
            if(vis[r][c])
            {
                ans.push_back(count);
                continue;
            }
            
            vis[r][c] = 1;
            count++;

            for(int i=0; i<4; i++)
            {
                int row = r + dr[i], col = c + dc[i];
                if(row>=0 and row<n and col>=0 and col<m and vis[row][col] and ds.findParent(m*row + col) != ds.findParent(m*r + c))
                {
                    ds.UnionBySize(m*row + col, m*r + c);
                    count--;
                }
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends