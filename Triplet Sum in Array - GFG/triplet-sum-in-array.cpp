// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        
        for(int f=0; f<n-2; f++)
        {
            int sum = X-A[f];
            int i=f+1, j=n-1;
            
            while(i < j)
            {
                if(A[i]+A[j] == sum)
                    return true;
                else if(A[i]+A[j] > sum)
                    j--;
                else
                    i++;
                
            }
            
        }
        
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends