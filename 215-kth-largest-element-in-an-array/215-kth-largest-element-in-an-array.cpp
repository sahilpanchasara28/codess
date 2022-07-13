class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(auto i: nums)
        {
            if(minheap.size() < k)
                minheap.push(i);
            else if(i > minheap.top())
            {
                minheap.pop();
                minheap.push(i);
            }
        }
        
        return minheap.top();
    }
};