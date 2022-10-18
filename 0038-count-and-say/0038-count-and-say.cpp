class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
            string s = countAndSay(n - 1);
            int i = 0;
            string ans = "";
            for (i = 0; i < s.length(); ++i)
            {
                int k = 1;
				
                while (i < s.length() - 1 && s[i] == s[i + 1]) ++k, ++i;
                ans += to_string(k);
                ans += s[i];
            }
            return ans;
    }
};