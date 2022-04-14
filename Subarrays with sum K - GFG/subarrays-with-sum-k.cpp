// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
        // code here
        
        unordered_map<int, int> m;
        int currSum = 0, res = 0;
        
        for(int i=0; i<N; i++)
        {
            currSum += arr[i];
            
            if(currSum == k)
                res++;
                
            if(m.find(currSum-k) != m.end())
                res += m[currSum-k];
                
            m[currSum]++;
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends