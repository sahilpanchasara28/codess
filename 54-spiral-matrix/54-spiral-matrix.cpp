class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        int rs = 0, re = n-1, cs = 0, ce = m-1, c = 0, total = n*m;
        
        while(c < total) 
        {
            for(int j=cs; c < total && j<=ce; j++)
            {
                ans.push_back(mat[rs][j]);
                c++;
            }
            rs++;

            for(int i=rs; c < total && i<=re; i++) 
            {
                ans.push_back(mat[i][ce]);
                c++;
            }
            ce--;

            for(int j=ce; c < total && j>=cs; j--) 
            {
                ans.push_back(mat[re][j]);
                c++;
            }
            re--;

            for(int i=re; c < total && i>=rs; i--) 
            {
                ans.push_back(mat[i][cs]);
                c++;
            }
            cs++;
        }
        
        return ans;
    }
};