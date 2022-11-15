class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        
        string check = "";
        
        for(auto i: words)
        {
            check += i;
            if(check == s)
                return true;
        }
        
        return false;
    }
};