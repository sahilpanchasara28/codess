class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        int ans = 1e9;
        
        for(int i=0; i<n; i++)
        {
            if(words[i] == target)
                ans = min(ans, 
                          min(abs(startIndex - i),  // left distance
                              n-abs(startIndex - i)) // right distance
                         );
        }
        
        if(ans == 1e9)
            return -1;
        
        return ans;
    }
};