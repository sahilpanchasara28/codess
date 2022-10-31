class Solution {
public:
    int destroyTargets(vector<int>& arr, int space) {
        int n = arr.size();
        vector<int> temp = arr;
        
        for(int i=0; i<n; i++)
            temp[i] %= space;
        
        map<int, int> m;
        for(auto i: temp)
            m[i]++;
        
        int maxi = -1;
        vector<int> ans;
        
        for(auto i: m)
        {
   
            if(maxi == -1)
            {
                maxi = i.second;
                ans.push_back(i.first);
            }
            else if(maxi == i.second)
                ans.push_back(i.first);
            
            else if(maxi < i.second)
            {
                maxi = i.second;
                ans.assign(0, 0);
                ans.push_back(i.first);
            }
        }
        
        unordered_set<int> s;
        for(auto i: ans)
            s.insert(i);
        
        int qwe = INT_MAX;
        for(int i=0; i<n; i++)
            if(s.count(temp[i]))
                qwe = min(qwe, arr[i]);
        
        return qwe;
    }
};