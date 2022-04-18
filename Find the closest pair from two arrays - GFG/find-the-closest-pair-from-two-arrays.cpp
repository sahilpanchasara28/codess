// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int a[], int b[], int n, int m, int x) {
        //code here
        
        pair<int, int> ans;
        int diff = INT_MAX;
        
        int i = 0, j = m-1;
        
        while(i<n && j >= 0)
        {
            if(abs(a[i]+b[j] - x) < diff)
            {
                ans.first = a[i];
                ans.second = b[j];
                diff = abs(a[i]+b[j]-x);
            }
            
            if(a[i]+b[j] < x)
                i++;
            else
                j--;
        }
        
        vector<int> res {ans.first, ans.second};
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends