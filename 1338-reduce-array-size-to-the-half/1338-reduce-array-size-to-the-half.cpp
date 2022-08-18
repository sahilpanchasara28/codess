bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second > b.second;
}

class Solution {
public:
    
    
    int minSetSize(vector<int>& arr) {
        
    unordered_map<int, int> m;
    
    for(int i: arr)
        m[i]++;
    
    int n = arr.size()/2;
        
    vector<pair<int, int> > A;
  
    for (auto& it : m) {
        A.push_back(it);
    }
  
    sort(A.begin(), A.end(), cmp);
    
    int sum = 0, len = 0;
        
    for(auto i: A)
    {
        sum += i.second;
        len++;
        if(sum >= n)
            break;
    }
        
    return len;
    }
};