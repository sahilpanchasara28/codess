class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(temp != "")
                {
                    st.push(temp + ' ');
                    temp = "";
                }
            }
            else
                temp.push_back(s[i]);
        }
        
        if(temp != "")
            st.push(temp + ' ');
        
        temp = "";
        while(!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        
        temp.pop_back();
        return temp;
    }
};