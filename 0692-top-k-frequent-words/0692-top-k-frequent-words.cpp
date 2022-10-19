class Solution {
public:
    struct comp{
    bool operator()(pair<string, int> &p1, pair<string, int> &p2)
    {
        if(p1.second == p2.second)
            return p1.first < p2.first;
        
        return p1.second > p2.second;
    }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> m;
        
        for(auto i: words)
            m[i]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> minHeap;
        
        for(auto i: m)
        {
            minHeap.push({i.first, i.second});
            
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        vector<string> ans;
        while(!minHeap.empty())
        {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};