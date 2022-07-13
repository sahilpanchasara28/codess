class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto i: nums)
            m[i]++;
        
        auto comp = [&m](int n1, int n2) { return m[n1] > m[n2]; };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for(auto i: m)
        {
            pq.push(i.first);
            if(pq.size() > k)
                pq.pop();
        }
            
        vector<int> ans(k);
        for(int i=k-1; i>=0; i--)
        {
            ans[i] = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};