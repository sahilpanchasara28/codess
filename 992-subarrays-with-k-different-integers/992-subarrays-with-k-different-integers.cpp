class Solution {
public:
    int func1(vector<int>& s, int k)
    {
        int ans = 0, start = 0, end = 0;
        int n = s.size();
        
        unordered_map<int, int> m;
        
        while(end < n)
        {
            m[s[end++]]++;
            
            while(m.size() > k)
            {
                m[s[start]]--;
                
                if(m[s[start]] == 0)
                    m.erase(s[start]);
                start++;
            }
            
            ans += (end-start+1);
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& s, int k) {
        return func1(s,k)-func1(s,k-1);
        
    }
};