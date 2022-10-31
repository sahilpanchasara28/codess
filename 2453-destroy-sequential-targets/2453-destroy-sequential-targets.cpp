class Solution {
public:
    int destroyTargets(vector<int>& arr, int space) {
        int n = arr.size();
        vector<int> temp = arr;
        
        for(int i=0; i<n; i++)
            temp[i] %= space;
        
        unordered_map<int, int> m;
        for(auto i: temp)
            m[i]++;
        
        int maxi = -1;
        unordered_set<int> ind;
        
        for(auto i: m)
        {
   
            if(maxi == -1)
            {
                maxi = i.second;
                ind.insert(i.first);
            }
            else if(maxi == i.second)
                ind.insert(i.first);
            
            else if(maxi < i.second)
            {
                maxi = i.second;
                ind.clear();
                ind.insert(i.first);
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++)
            if(ind.count(temp[i]))
                ans = min(ans, arr[i]);
        
        return ans;
    }
};