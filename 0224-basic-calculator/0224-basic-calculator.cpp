class Solution {
public:
    int calculate(string s) {
       
        int n = s.length();
        stack<int> stk ;
        int res = 0;
        int sign = 1;
        
        for(int i = 0 ; i < n ; i++){
            
            if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(isdigit(s[i])){
                long long temp = 0;
                
                while(i < n and isdigit(s[i])){
                    temp = temp*10 + s[i] - '0';
                    i++;
                }
                i--;
                res = res + sign*temp;
            }
            else if(s[i] == '('){
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                int curr_sign = stk.top(); stk.pop();
                int curr_val = stk.top(); stk.pop();
                
                res = curr_val + curr_sign * res;
            }
        }
        return res;
    }
};