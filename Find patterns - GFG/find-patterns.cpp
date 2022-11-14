//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int numberOfSubsequences(string S, string W){
        
        int ans = 0;
        int i=0, j=0, n=S.size(), m=W.size();
        
        while(i<n)
        {
            if(S[i] == W[j])
            {
                S[i] = '$';
                j++;
            }
            
            i++;
            
            if(j == m)
            {
                ans++;
                i = j = 0;
            }
        }
        
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends