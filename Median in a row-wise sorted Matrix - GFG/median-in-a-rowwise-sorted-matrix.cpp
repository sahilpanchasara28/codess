//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int R, int C){
        
        int mini = 1e9, maxi = -1e9;
        
        for(int i=0; i<R; i++)
        {
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][C-1]);
        }
        
        while(mini < maxi)
        {
            int mid = (mini+maxi)/2;
            
            int want = (R*C + 1)/2;
            
            int count = 0;
            for(int i=0; i<R; i++)
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
                
            if(count < want)
                mini = mid+1;
            else
                maxi = mid;
        }
        
        return mini;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends