class Solution {
public:
    bool isItPossible(string w1, string w2) {
        
        unordered_map<char, int> m1, m2;
        
        for(auto i: w1)
            m1[i]++;
        
        for(auto i: w2)
            m2[i]++;
        
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                char ch1 = i+'a', ch2 = j+'a';
                
                if(m1.count(ch1) and m2.count(ch2))
                {
                    m1[ch1]--;
                    m2[ch2]--;

                    if(m1[ch1] == 0)
                        m1.erase(ch1);

                    if(m2[ch2] == 0)
                        m2.erase(ch2);

                    m1[ch2]++;
                    m2[ch1]++;

                    if(m1.size() == m2.size())
                        return true;

                    // backtrack

                    m1[ch2]--;
                    m2[ch1]--;

                    if(m1[ch2] == 0)
                        m1.erase(ch2);

                    if(m2[ch1] == 0)
                        m2.erase(ch1);

                    m1[ch1]++;
                    m2[ch2]++;
                }
            }
        }
        
        return false;
    }
};