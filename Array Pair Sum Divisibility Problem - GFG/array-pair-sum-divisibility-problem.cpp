//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int> m;
        
        for(auto i: nums)
            m[i%k]++;
            
        for(auto i: nums)
        {
            int rem = i%k;
            
            if(rem == 0) // already multiple of k, so can only pair with similar multiple
            {
                if(m[rem] & 1) // if count is odd
                    return false;
            }
            else
            {
                if(m[rem] != m[k-rem]) // both count is diff
                    return false;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends