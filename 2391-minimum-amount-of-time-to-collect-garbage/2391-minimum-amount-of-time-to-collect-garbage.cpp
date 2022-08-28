class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& t) {
        
        unordered_map<char, int> m;
        unordered_map<char, int> last;
        
        for(int i=0; i<gar.size(); i++)
        {
            for(auto &j: gar[i])
            {
                m[j]++;
                last[j] = i;
            }
        }
        
        vector<int> sum(t.size(), 0);
        sum[0] = t[0];
        
        for(int i=1; i<t.size(); i++)
            sum[i] = sum[i-1] + t[i];
        
        int ans = 0;
        
        string temp = "GMP";
        
        for(auto i: temp)
        {
            if(m[i] != 0 && last[i] != 0)
                ans += (m[i] + sum[last[i] - 1]);
            else if(m[i] != 0 && last[i] == 0)
                ans += m[i];
        }
        
        return ans;
    }
};