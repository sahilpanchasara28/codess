class Solution {
public:
    
    int sum(int a, int b)
    {
        if(a == 1 and b == 1)
            return 10;
        return a+b;
    }
    
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0, j=0;
        string ans = "";
        int carry = 0;
        int n = a.size(), m = b.size();
        
        while(i<n and j<m)
        {
            int currSum = sum(a[i]-'0', b[j]-'0');
            currSum = sum(currSum, carry);
            
            carry = currSum/10;
            ans += (currSum%10 + '0');
            i++;
            j++;
        }
        
        while(i<n)
        {
            int currSum = sum(a[i]-'0', carry);
            
            carry = currSum/10;
            ans += (currSum%10 + '0');
            i++;
        }
        
        while(j<m)
        {
            int currSum = sum(b[j]-'0', carry);
            
            carry = currSum/10;
            ans += (currSum%10 + '0');
            j++;
        }
        
        if(carry == 1)
            ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};