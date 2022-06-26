// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void dfs(int i, int j, int n, vector<vector<int>> &mat, string temp, vector<string> &ans)
    {
        if(i<0 || i>=n || j<0 || j>=n || mat[i][j] != 1)
            return;
        
        if(i == n-1 && j == n-1)
        {
            ans.push_back(temp);
            return;
        }
        
        int origin = mat[i][j];
        mat[i][j] = 2;

        temp.push_back('U');
        dfs(i-1, j, n, mat, temp, ans);
        temp.pop_back();
        
        temp.push_back('D');
        dfs(i+1, j, n, mat, temp, ans);
        temp.pop_back();
        
        temp.push_back('L');
        dfs(i, j-1, n, mat, temp, ans);
        temp.pop_back();
        
        temp.push_back('R');
        dfs(i, j+1, n, mat, temp, ans);
        temp.pop_back();
        
        mat[i][j] = origin;
    }
    
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0)
            return ans;
        
        string temp;
        dfs(0, 0, n, mat, temp, ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends