//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    char reVal(int num)
    {
        if (num >= 0 && num <= 9)
            return (char)(num + '0');
        else
            return (char)(num - 10 + 'A');
    }
  
    string fromDtoB(int base, int inputNum)
    {
        string res = "";
        while (inputNum > 0) {
     
            res += reVal(inputNum % base);
     
            inputNum /= base;
        }
     
        reverse(res.begin(), res.end());
     
        return res;
    }
  
    string baseEquiv(int n, int m){
        
        for(int b=2; b<=32; b++)
        {
            string ans = fromDtoB(b, n);
            if(ans.size() == m)
                return "Yes";
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends