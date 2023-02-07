class Solution {
public:
    int totalFruit(vector<int>& arr) {
        
        unordered_map<int, int> m;
        
        int n = arr.size();
        int i=0,j=0;
        int ans = 0;
        
        while(j < n)
        {
            m[arr[j]]++;
            
            if(m.size() > 2)
            {
                m[arr[i]]--;
                if(m[arr[i]] == 0)
                    m.erase(arr[i]);
                
                i++;
            }
            
            j++;
        }
        
        return j-i;
    }
};