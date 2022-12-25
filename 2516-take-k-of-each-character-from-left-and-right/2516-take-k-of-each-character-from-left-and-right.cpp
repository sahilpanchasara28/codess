class Solution {
public:
    
    bool check(unordered_map<char, int> &freq, unordered_map<char, int> &window, int k)
    {
        for(int i=0; i<3; i++)
        {
            if(window['a'+i] > freq['a'+i] - k)
                return true;
        }
        
        return false;
    }
    
    int takeCharacters(string s, int k) {
        unordered_map<char, int> freq;
        int n = s.size();
        
        for(auto i: s)
            freq[i]++;
        
        if(freq['a'] < k or freq['b'] < k or freq['c'] < k)
            return -1;
        
        unordered_map<char, int> window;
        int ans = 1e9;
        int i=0, j=0;
        
        while(j < n)
        {
            window[s[j]]++;
            j++;
            
            while(check(freq, window, k))
            {
                window[s[i]]--;
                i++;
            }
            
            ans = min(ans, n - (j-i));
        }
        
        return ans;
    }
};