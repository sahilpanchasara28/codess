class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size() == 1)
            return "";
        
        string temp = s;
        int n = s.size();
        
        for(int i=0; i<n; i++)
            if(temp[i] != 'a' && i != n/2)
            {
                temp[i] = 'a';
                break;
            }
        
        if(temp == s)
            temp[n-1] = 'b';
        
        return temp;
    }
};