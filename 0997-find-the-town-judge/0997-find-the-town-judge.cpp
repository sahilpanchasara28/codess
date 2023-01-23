class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        
        vector<int> count(n, 0);
        vector<int> count1(n, 0);
        
        for(auto i: t)
        {
            count[i[1]-1]++;
            count1[i[0]-1]++;
        }
        
        for(int i=0; i<n; i++)
            if(count[i] == n-1 and count1[i] == 0)
                return i+1;
        
        return -1;
    }
};