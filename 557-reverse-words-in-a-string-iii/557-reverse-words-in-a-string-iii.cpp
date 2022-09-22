class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(auto i: s)
        {
            if(i == ' ')
            {
                ans += temp;
                ans += " ";
                temp = "";
            }
            else
                temp = i+temp;
        }
        
        if(temp != "")
            ans += temp;
        return ans;
    }
};