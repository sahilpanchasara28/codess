class Solution {
public:
    
    void dfs(vector<vector<int>>& arr, int i, int j, int n, int m, int prev, vector<vector<bool>>& vis)
        
    {
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || arr[i][j] < prev)
            return;
        
        vis[i][j] = 1;
        
        dfs(arr, i-1, j, n, m, arr[i][j], vis);
        dfs(arr, i+1, j, n, m, arr[i][j], vis);
        dfs(arr, i, j-1, n, m, arr[i][j], vis);
        dfs(arr, i, j+1, n, m, arr[i][j], vis);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        
        int n = arr.size(), m = arr[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m , 0));

        //first row
        for(int j=0; j<m; j++)
            dfs(arr, 0, j, n, m, arr[0][j], pacific);
        
        //first col
        for(int i=0; i<n; i++)
            dfs(arr, i, 0, n, m, arr[i][0], pacific);
        
        vector<vector<bool>> atlantic(n, vector<bool>(m , 0));

        //last row
        for(int j=0; j<m; j++)
            dfs(arr, n-1, j, n, m, arr[n-1][j], atlantic);
        
        //last col
        for(int i=0; i<n; i++)
            dfs(arr, i, m-1, n, m, arr[i][m-1], atlantic);
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        
        return ans;
    }
};