//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        int sum = 0;
        
        multiset<int> s;
        
        for(auto i: arr)
            s.insert(i);
        
        while(s.size() > 1) {
            auto it = s.begin();
            int two = *it;
            s.erase(it);
        
            it = s.begin();
            two += *it;
            s.erase(it);
            
            sum += two;
            s.insert(two);
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends