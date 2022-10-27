//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int arr[], int i, int j, int n, vector<int> &ans)
    {
        if(i > j)
            return;
        
        if(i == j)
        {
            ans.push_back(arr[i]);
            return;
        }
        
        int ind = j+1;
        for(int k=i+1; k<=j; k++)
        {
            if (arr[k] > arr[i])
            {
                ind = k;
                break;
            }
        }
    
        solve(arr, i+1, ind-1, n, ans);
        solve(arr, ind, j, n, ans);
    }
  
    vector<int> leafNodes(int arr[],int N) {
        vector<int> ans;
        solve(arr, 0, N-1, N, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends