class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> check[26];
        
        for(auto &s: ideas)
            check[s[0] - 'a'].insert(s.substr(1));
        
        long long ans = 0;
        
        for(int i=0; i<25; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                int mutual = 0;
                
                for(auto &it: check[i])
                {
                    if(check[j].count(it))
                        mutual++;
                }
                
                ans += (2LL * (check[i].size() - mutual) * (check[j].size() - mutual)); 
            }
        }
    
        return ans;
    }
};