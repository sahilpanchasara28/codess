class Solution {
public:
    int minimumPartition(string s, int k) {
        
        int ans = 0;
        int n = s.size();
        
        string temp = "";
        for(int i=0; i<n;)
        {
            temp += s[i];
            if(stol(temp) > k)
            {
                if(temp.size() == 1)
                    return -1;
                
                ans++;
                temp = "";
            }
            else
                i++;
        }
        
        return ans+1;
    }
};