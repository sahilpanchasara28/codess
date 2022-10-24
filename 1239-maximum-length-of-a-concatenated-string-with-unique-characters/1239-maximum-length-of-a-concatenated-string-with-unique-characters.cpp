class Solution {
public:
    
    bool checkUnique(string a)
    {
        unordered_set s(begin(a), end(a));
        return (a.size() == s.size());
    }
        
    
    void solve(vector<string>& unique, int ind, string curr, int &ans)
    {
        if(ind == -1)
            return;
        
        //exclude
        bool isUnique = checkUnique(curr);
        solve(unique, ind-1, curr, ans);
        ans = max(ans, (int)curr.size());
        
        //include
        curr = unique[ind] + curr;
        isUnique = checkUnique(curr);
        if(isUnique)
        {
            solve(unique, ind-1, curr, ans);
            ans = max(ans, (int)curr.size());
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<string> unique;
        int ans = 0;
        
        for(auto i: arr)
        {
            bool isUnique = checkUnique(i);
            if(isUnique)
            {
                ans = max(ans, (int)i.size());
                unique.push_back(i);
            }
        }
        
        int n = unique.size();
        if(n > 0)
            solve(unique, n-1, "", ans);
        
        return ans;
    }
};