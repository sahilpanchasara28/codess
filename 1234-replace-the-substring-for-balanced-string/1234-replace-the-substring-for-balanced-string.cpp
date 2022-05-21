class Solution {
public:
    
    bool isBal(unordered_map<char, int> &m, int n)
    {
        if(m['Q'] <= n && m['W'] <= n && m['E'] <= n && m['R'] <= n)
            return true;
        return false;
    }
    
    int balancedString(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        
        for(int i=0; i<n; i++)
            m[s[i]]++;
        
        if(isBal(m, n/4))
            return 0;
        
        int left = 0, right, ans = INT_MAX;
        
        for(right = 0; right < n; right++)
        {
            m[s[right]]--;
            
                while(left <= right && isBal(m, n/4))
                {
                    ans = min(ans, right-left+1);
                    m[s[left]]++;
                    left++;
                }
        }
        
        return ans;
    }
};