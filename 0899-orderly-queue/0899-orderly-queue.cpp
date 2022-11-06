class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        string ans = s;
        int n = s.size();
        
        if(k == 1)
        {
            for(int i=0; i<n; i++)
                ans = min(ans, s.substr(i) + s.substr(0, i));
        }
        else
            sort(ans.begin(), ans.end());
        
        return ans;
    }
};