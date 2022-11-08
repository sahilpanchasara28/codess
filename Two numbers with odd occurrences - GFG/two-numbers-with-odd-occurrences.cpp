//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int N)  
    {
        long long int xor2 = arr[0]; 
        long long int set_bit_no;
        long long int i;
        long long int n = N - 2;
        long long int x = 0, y = 0;
         
        for(i = 1; i < N; i++)
            xor2 = xor2 ^ arr[i];
         
        set_bit_no = xor2 & ~(xor2-1);
         
        for(i = 0; i < N; i++)
        {
            if(arr[i] & set_bit_no)
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
        
        if(x < y)
            return {y, x};
        return {x, y};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends