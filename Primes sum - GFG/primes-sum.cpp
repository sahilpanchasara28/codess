//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int n){
        
        vector<bool> prime(n+1, true);
        
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true)
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
        }
     
        vector<int> vec;
        for (int p = 2; p <= n; p++)
            if (prime[p])
                vec.push_back(p);
                
        int i=0, j = vec.size()-1;
        while(i<=j)
        {
            if(vec[i]+vec[j] == n)
                return "Yes";
            else if(vec[i]+vec[j] > n)
                j--;
            else
                i++;
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends