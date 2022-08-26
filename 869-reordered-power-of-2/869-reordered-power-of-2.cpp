class Solution {
public:
    vector<int> count(int n)
    {
        vector<int> ans(10, 0);
        
        while(n > 0){
            ans[n%10]++;
            n/=10;
        }
        
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> original = count(n);
        
        for(int i=0; i<31; i++)
        {
            vector<int> calculated = count(1 << i); // 1 << i is nothing but 2^i , iterating over power of twos
            if(original == calculated)
                return true;
        }
        return false;
    }
};