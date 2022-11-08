class Solution {
public:
    string makeGood(string s) {
        
        if(s.empty())
            return s;
        
        int n = s.size();
        string ans = "";
        stack<char> st;
        
        for(int i=0; i<n; i++)
        {
            if(!st.empty() and (st.top() - 32 == s[i] or st.top() + 32 == s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};