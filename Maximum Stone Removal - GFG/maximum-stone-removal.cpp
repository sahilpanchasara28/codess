//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int maxRow = 0, maxCol = 0;
        
        for(auto it: stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        
        unordered_set<int> s;
        for(auto it: stones)
        {
            int nrow = it[0];
            int ncol = it[1] + maxRow+1;
            
            ds.UnionBySize(nrow, ncol);
            s.insert(ds.findParent(nrow));
            s.insert(ds.findParent(ncol));
        }
        
        int comp = 0;
        for(auto it: s)
            if(ds.findParent(it) == it)
                comp++;

        return n-comp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x; cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj,n) << "\n";
    }
}
// } Driver Code Ends