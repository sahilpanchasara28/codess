class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        
        sort(arr.begin(), arr.end(), cmp);
        
        int maxD = 0;
        int ans = 0;
        
        for(auto &x: arr)
        {
            if(x[1] < maxD)
                ans++;
            
            maxD = max(maxD, x[1]);
        }
        
        return ans;
    }
};