class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m=mat[0].size();
        
        int maxi = -1e9;
        for(int left=0; left<m; left++)
        {
            vector<int> curr(n, 0);
            for(int right=left; right<m; right++)
            {
                for(int i=0; i<n; i++)
                    curr[i] += mat[i][right];
                
                for(int i=0; i<n; i++)
                {
                    int sum = 0;
                    for(int j=i; j<n; j++)
                    {
                        sum += curr[j];
                        
                        if(sum <= k && sum > maxi)
                            maxi = sum;
                    }
                }
            }
        }
        
        return maxi;
    }
};