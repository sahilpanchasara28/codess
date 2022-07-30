class Solution {
public:
    
    vector<int> get_freq(string word)
    {
        vector<int> ans(26, 0);
        for(auto i: word)
            ans[i-'a']++;
        return ans;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        
        vector<int> max_freq_w2(26, 0);
        
        for(auto w: words2)
        {
            vector<int> curr_freq = get_freq(w);
            
            for(auto i: w)
                max_freq_w2[i-'a'] = max(curr_freq[i-'a'], max_freq_w2[i-'a']);
        }
        
        for(auto w: words1)
        {
            bool f = 1;
            vector<int> curr_freq = get_freq(w);
            for(int i=0; i<26; i++)
            {
                if(curr_freq[i] < max_freq_w2[i])
                {
                    f = 0;
                    break;
                }
            }
            
            if(f)
                ans.push_back(w);
        }
        
        return ans;
    }
};