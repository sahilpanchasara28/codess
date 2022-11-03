class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        
        for(auto it: words)
            m[it]++;
                
        int count = 0;
        bool cent = false;
        
        for(auto it: m)
        {
            string curr = it.first;            
            
            if(curr[0] == curr[1])
            {
                if(m[curr] % 2 == 0)
                    count += m[curr];
                else
                {
                    count += m[curr] - 1;
                    cent = true;
                }
            }
            else if(curr[0] < curr[1] && m.count({curr[1] , curr[0]}))
                count += 2*min(m[curr], m[{curr[1] , curr[0]}]);
            
        }
        
        if(cent)
            count++;
        
        return count*2;
    }
};