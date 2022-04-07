class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        
        ans[0] = {1};
        if(n == 1)
            return ans;
        
        ans[1] = {1,1};
        if(n == 2)
            return ans;
    
        for(int i=2; i<n; i++)
        {
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++)  //excluding first and last elements
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            
            ans[i] = temp;
        }
        return ans;
    }
};