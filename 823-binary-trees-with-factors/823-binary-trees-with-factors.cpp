class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        unordered_map<int, long long> m;
        
        for(int i: arr)
            m[i] = 1;
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(arr[i]%arr[j] == 0 && m.find(arr[i]/arr[j]) != m.end())
                {
                        m[arr[i]] += m[arr[j]]*(m[arr[i]/arr[j]]);            
                }
            }
        }
        
        int ans = 0;
        for(auto i: m)
            ans = (ans%mod + i.second%mod)%mod;
        return ans;
    }
};