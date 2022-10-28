//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
		int NthTerm(int n){
		      long ans = 1;

     int i = 1;

     long mod = 1000000007;

     while(n != 0){

         ans = (ans*i)%mod + 1;

         n--;

         i++;

     }

     return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends