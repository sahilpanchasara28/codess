class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        
        for(auto i: gifts)
            pq.push(i);
        
        while(k--)
        {
            auto top = pq.top();
            pq.pop();
            
            int val = sqrt(top);
            
            pq.push(val);
        }
        
        long long ans = 0;
        
        while(!pq.empty())
        {
            ans += (pq.top());
            pq.pop();
        }
        
        return ans;
    }
};