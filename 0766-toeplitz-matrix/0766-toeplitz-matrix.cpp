class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i>0 and j>0 and mat[i][j] != mat[i-1][j-1])
                    return false;
            }
        } 
        
        return true;
    }
};