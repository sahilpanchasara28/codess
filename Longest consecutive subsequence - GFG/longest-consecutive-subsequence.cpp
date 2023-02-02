//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        vector<bool> m(1e5+1, 0);
        
        for(int i=0; i<N; i++)
            m[arr[i]] = 1;
            
        int maxLen = 0, currLen = 1;
        for(int i=1; i<m.size(); i++)
        {
            if(m[i-1] and m[i])
                currLen++;
            else
            {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        
        return max(maxLen, currLen);
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends