//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long maxi = arr[0], curr1 = 1, curr2 = 1;
	    
	    for(int i=0; i<n; i++)
	    {
	        curr1 *= arr[i];
	        curr2 *= arr[n-i-1];
	        
	        maxi = max({maxi, curr1, curr2});
	        
	        if(curr1 == 0)
	            curr1 = 1;
	            
	        if(curr2 == 0)
	            curr2 = 1;
	    }
	   
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends