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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        
        for(auto i: stones)
        {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        
        DisjointSet dsu(maxRow + maxCol + 1);
        
        unordered_set<int> s;
        for(auto i: stones)
        {
            int newRow = i[0];
            int newCol = i[1]+maxRow+1;
            
            dsu.UnionBySize(i[0], newCol);
            
            s.insert(dsu.findParent(newRow));
            s.insert(dsu.findParent(newCol));
        }
        
        int c = 0;
        for(auto i: s)
        {
            if(dsu.findParent(i) == i)
                c++;
        }
        
        return stones.size() - c;
    }
};