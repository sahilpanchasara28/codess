//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int tn = -1, tnp1 = 0, tnp2 = 0;
        
        for(int i=0; i<N; i++)
        {
            int cwtn = arr[i] & tn;
            int cwtnp1 = arr[i] & tnp1;
            int cwtnp2 = arr[i] & tnp2;
            
            tn = tn & (~cwtn);
            tnp1 = tnp1 | cwtn;
            
            tnp1 = tnp1 & (~cwtnp1);
            tnp2 = tnp2 | cwtnp1;
            
            tnp2 = tnp2 & (~cwtnp2);
            tn = tn | cwtnp2;
        }
        
        return tnp1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends