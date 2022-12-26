class Solution {
public:
    int fact[100002];
    int mod = 1e9+7;
    
    int modMul(int a, int b) {
        return ((long long)(a % mod) * (b % mod))%mod;
    }
    
    int binaryExpo(int a, int b) {
        if(!b)
            return 1;
        
        int res = binaryExpo(a,b/2);
        
        if(b&1)
            return modMul(a,modMul(res,res));
        else
            return modMul(res,res);
    }
    
    int modMulInv(int a) {
        return binaryExpo(a, mod-2);
    }
    
    void calculateFact() {
        fact[0] = 1;
        
        for(int i=1; i<100002; i++)
            fact[i] = modMul(fact[i-1], i);
    }
    
    int ways(string word) {
        unordered_map<char, int> m;
        
        for(auto i: word)
            m[i]++;
        
        int totWays = fact[word.size()];
        
        int remFact = 1;
        
        for(auto i: m)
            remFact = modMul(remFact, fact[i.second]);
        
        return modMul(totWays, modMulInv(remFact));
    }
    
    int countAnagrams(string s) {
        calculateFact();
        
        istringstream ss(s);
        string word; 
        
        int ans=1;
        
        while (ss >> word)
        {
            ans=modMul(ans,ways(word));
        }
        return ans;
        
    }
};