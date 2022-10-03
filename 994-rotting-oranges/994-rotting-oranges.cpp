class Solution {
public:
    
    bool isSafe(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        return (i >= 0 && i < n && j >=0 && j < m && grid[i][j] == 1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> q;
        int c1 = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j, 0});
                
                if(grid[i][j] == 1)
                    c1++;
            }
        }
        
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        
        int tm = 0, c = 0;
        while(!q.empty())
        {
                auto front = q.front();
                q.pop();
                
                tm = max(tm, front[2]);
                
                for(int ind = 0; ind<4; ind++)
                {
                    int ni = front[0] + row[ind];
                    int nj = front[1] + col[ind];
                    
                    if(isSafe(ni, nj, n, m, grid))
                    {
                        grid[ni][nj] = 2;
                        q.push({ni, nj, front[2]+1});
                        c++;
                    }
                }
        }
        
        if(c != c1)
            return -1;
        
        return tm;
    }
};