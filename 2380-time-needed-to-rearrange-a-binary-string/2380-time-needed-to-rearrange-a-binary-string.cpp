class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        
        int n = s.size();
        int c = 0;
        bool check = 1;
        
        while(check)
        {
            check = 0;
            for(int i=1; i<n; )
            {
                if(s[i-1] == '0' && s[i] == '1')
                {
                        check = 1;
                        swap(s[i-1], s[i]);
                        i+=2;
                }
                else
                    i++;
            }
            
            if(check)
                c++;
            
        }
        
        
        return c;
    }
};