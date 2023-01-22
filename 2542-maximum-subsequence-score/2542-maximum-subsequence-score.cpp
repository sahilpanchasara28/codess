class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        int n = nums1.size();
        
        for(int i=0; i<n; i++)
            arr.push_back({nums2[i], nums1[i]});
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>> ());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, res = 0;
        
        for(auto it: arr)
        {
            int first = it.first;
            int second = it.second;
            
            pq.push(second);
            sum += second;
            
            if(pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k)
                res = max(res, sum * first);
        }
        
        return res;
    }
};