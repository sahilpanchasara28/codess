class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        
        int tot = 0;
        
        for(int i=0; i<t.size()-1; i++)
            tot += min(t[i+1] - t[i], d);
        
        return tot + d;
    }
};