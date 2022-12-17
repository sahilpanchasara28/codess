class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        
        for(auto i: tokens)
        {
            if(i == "+" or i == "-" or i == "*" or  i == "/")
            {
                long x = s.top();
                s.pop();
                
                long y = s.top();
                s.pop();
                                
                if(i == "+")
                    s.push(y+x);
                else if(i == "-")
                    s.push(y-x);
                else if(i == "*")
                    s.push(y*x);
                else
                    s.push(y/x);
            }
            else
                s.push(stoi(i));
        }
        
        return s.top();
    }
};