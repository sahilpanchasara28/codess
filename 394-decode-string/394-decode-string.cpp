class Solution {
public:
    string decodeString(string s) {
        
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != ']')
                ans.push_back(s[i]);
            else
            {
                string temp = "";
                while(ans.back() != '[')
                {
                    temp = ans.back() + temp;
                    ans.pop_back();
                }
                ans.pop_back(); // to remove '['
                
                string num = "";
                while(ans.size() && ans.back() >= '0' && ans.back() <= '9')
                {
                    num = ans.back() + num;
                    ans.pop_back();
                }
                
                int n = stoi(num);
                while(n--)
                    ans += temp;
            }
        }
        
        return ans;
    }
};