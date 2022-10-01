class Solution {
public:
    
    int solve(string s)
    {
        int n = s.size();
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '0')
                continue;

            int single_digit = stoi(s.substr(i, 1));
            int double_digit = stoi(s.substr(i, 2));

            int one = 0, two = 0;

            if(single_digit >= 1 && single_digit <= 9)
                one = dp[i+1];

            if(double_digit >= 10 && double_digit <= 26)
                two = dp[i+2];

            dp[i] = one+two;
        }
        
        return dp[0];
    }
    
    int numDecodings(string s) {

        return solve(s);
    }
};