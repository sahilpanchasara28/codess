class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        
        for(auto n: nums)
        {
            while (n%2 == 0) 
            { 
                ans.insert(2); 
                n = n/2; 
            } 
            
            for (int i = 3; i <= sqrt(n); i = i+2) 
            { 
                while (n%i == 0) 
                { 
                    ans.insert(i);
                    n = n/i; 
                } 
            } 

            if (n > 2) 
                ans.insert(n);
        }
        
        return ans.size();
    }
};