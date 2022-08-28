class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> s;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                s[j-i].push(mat[i][j]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mat[i][j] = s[j-i].top();
                s[j-i].pop();
            }
        }
        
        return mat;
    }
};