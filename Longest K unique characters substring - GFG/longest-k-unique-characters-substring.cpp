// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char, int> m;
        int n = s.size();
        
        for(int i=0; i<n; i++)
            m[s[i]]++;
        
        if(m.size() < k)
            return -1;
        
        m.clear();
        
        m[s[0]]++;
        int start = 0, end = 0, max_size = 1;
        
        for(int i=1; i<n; i++)
        {
            m[s[i]]++;
            end++;
            
            while(m.size() > k)
            {
                m[s[start]]--;
                
                if(m[s[start]] == 0)
                    m.erase(s[start]);
                start++;
            }
            
            if(end-start+1 > max_size)
                max_size = end-start+1;
            
        }
        
        return max_size;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends