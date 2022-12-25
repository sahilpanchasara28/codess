class Solution {
public:
    int captureForts(vector<int>& forts) {
        vector<int> idx;
        int n = forts.size();
        
        for(int i=0; i<n; i++)
            if(forts[i] != 0)
                idx.push_back(i); // storing the indexes of non - zero elements
        
        int ans = 0;
        for(int i=1; i<idx.size(); i++)
        {
            if(forts[idx[i-1]] * forts[idx[i]] == -1) // it means army can move
                ans = max(ans, abs(idx[i-1] - idx[i]) - 1); // get the max distance
        }
        
        return ans;
    }
};