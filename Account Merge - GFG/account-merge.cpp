//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string, int> m;
        
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                string curr = accounts[i][j];
                
                if(m.find(curr) == m.end())
                    m[curr] = i;
                else
                    ds.UnionBySize(m[curr], i);
            }
        }
        
        vector<string> temp[n];
        
        for(auto it: m)
        {
            int par = ds.findParent(it.second);
            temp[par].push_back(it.first);
        }
        
        
        vector<vector<string>> ans;
        
        for(int i=0; i<n; i++)
        {
            if(temp[i].size() == 0)
                continue;
                
            sort(temp[i].begin(), temp[i].end());
            temp[i].insert(temp[i].begin(), accounts[i][0]);
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends