class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        if(e1[0] < e2[0] and e1[1] < e2[0])
            return false;
        
        if(e1[0] > e2[1] and e1[1] > e2[1])
            return false;
        
        return true;
    }
};