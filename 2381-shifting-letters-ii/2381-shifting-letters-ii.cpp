class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        long n = s.size();
        vector<long> line(n+1, 0);
        
        for(auto sh: shifts)
        {
            if(sh[2])
            {
                line[sh[0]]++;
                line[sh[1]+1]--;
            }
            else
            {
                line[sh[0]]--;
                line[sh[1]+1]++;
            }
        }
        
        for(int i=1; i<=n; i++)
            line[i] += line[i-1];
        
        for(int i=0; i<n; i++)
        {
            long temp = (s[i]-'a' + line[i])%26;
            temp = (temp+26)%26;
            s[i] = 'a'+ temp;
        }
        
        return s;
    }
};