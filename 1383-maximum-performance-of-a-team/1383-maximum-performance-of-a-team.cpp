class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        
        vector<pair<int, int>> arr;
        
        for(int i=0; i<n; i++)
            arr.push_back({e[i], s[i]});
        
        sort(arr.rbegin(), arr.rend());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        long ans = 0, sum = 0;
        for(auto &[i,j]: arr)
        {
            minHeap.push(j);
            
            sum += j;
            
            if(minHeap.size() > k)
            {
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            ans = max(ans, sum*i);
        }
        
        return ans%1000000007;
    }
};