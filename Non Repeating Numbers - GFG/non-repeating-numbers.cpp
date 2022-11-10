//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int allXor = 0;
        
        for(auto i: nums)
            allXor ^= i;
        
        int right_bit = allXor & (~(allXor-1));
        int n1 = 0, n2 = 0;
        
        for(auto i: nums)
        {
            if(i & right_bit)
                n1 ^= i;
            else
                n2 ^= i;
        }
        
        if(n1 < n2)
            return {n1, n2};
        return {n2, n1};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends