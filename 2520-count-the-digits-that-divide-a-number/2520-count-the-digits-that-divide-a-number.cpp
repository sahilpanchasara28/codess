class Solution {
public:
    int countDigits(int num) {
        int n = num;
        int ans = 0;
        
        while(n > 0)
        {
            int last = n % 10;
            n /= 10;
            if(num % last == 0)
                ans++;
        }
        
        return ans;
    }
};