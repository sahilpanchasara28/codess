class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0) 
            return "";

        int digit = (n - 1) % 26;
        char letter = digit + 'A';
        
        return convertToTitle((n - digit) / 26) + letter;
    }
};