class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> arr(n);
        
        for(int i=0; i<n; i++)
            arr.push_back({growTime[i], plantTime[i]});
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>> ());
        
        int curr = 0, ans = -1e9;
        for(auto p: arr)
        {
            curr += (p.second);
            ans = max(ans, curr + p.first);
        }
        
        return ans;
    }
};