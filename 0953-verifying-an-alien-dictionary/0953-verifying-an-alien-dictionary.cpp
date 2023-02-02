class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ind;
        
        for(int i=0; i<order.size(); i++)
            ind[order[i]] = i;
        
        int n = words.size();
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<words[i-1].size(); j++)
            {
                
                if(j >= words[i].size())
                    return false;
                
                if(words[i-1][j] != words[i][j])
                {
                    if(ind[words[i-1][j]] > ind[words[i][j]])
                        return false;
                    else
                        break;
                }
            }
        }
        
        return true;
    }
};