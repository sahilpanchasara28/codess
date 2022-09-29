class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int, int>> pq;
        
        for(auto i: arr)
        {
            pq.push({abs(i-x), i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};