class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int n = s.size();
        int c = 0, zero = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                zero++;
            else if(zero > 0)
                c = max(c+1, zero);
        }
        
        return c;
    }
};