class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
         
        vector<bool> prime(right+1, 1);
        
        for (int p = 2; p * p <= right; p++) 
        {
            if (prime[p] == true) 
            {
                for (int i = p * p; i <= right; i += p)
                    prime[i] = false;
            }
        }
        
        int last = -1, diff = 1e9;
        vector<int> ans;
        
        for(int i=right; i>=left; i--)
        {
            if(prime[i])
            {
                if(last == -1)
                    last = i;
                else
                {
                    if(last-i <= diff and i != 1)
                    {
                        diff = last-i;
                        ans = {i, last};
                    }
                    last = i;
                }
            }   
        }
        
        if(diff == 1e9)
            return {-1, -1};
        
        return ans;
    }
};