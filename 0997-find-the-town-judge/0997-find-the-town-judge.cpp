class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        
        vector<int> count(n, 0);
        
        for(auto i: t)
        {
            count[i[0]-1]--;
            count[i[1]-1]++;
        }
        
        for(int i=0; i<n; i++)
            if(count[i] == n-1)
                return i+1;
        
        return -1;
    }
};