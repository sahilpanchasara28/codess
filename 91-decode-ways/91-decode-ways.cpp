class Solution {
public:
    
    int solve(string s, int i, vector<int> &dp)
    {
        if(i == s.size())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int single_digit = stoi(s.substr(i, 1));
        int double_digit = stoi(s.substr(i, 2));
        
        int one = 0, two = 0;
        
        if(single_digit >= 1 && single_digit <= 9)
            one = solve(s, i+1, dp);
        
        if(double_digit >= 10 && double_digit <= 26)
            two = solve(s, i+2, dp);
        
        return dp[i] = one+two;
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};