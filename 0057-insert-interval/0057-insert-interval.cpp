class Solution {
public:
    
    void mergeInterval(vector<vector<int>>& arr)
    {
        int last = 0;
        
        for(auto i: arr)
        {
            if(arr[last][1] >= i[0])
                arr[last][1] = max(arr[last][1], i[1]);
            else
            {
                last++;
                arr[last] = i;
            }
        }
        
        while(arr.size() > last+1)
            arr.pop_back();
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        bool f = 1;
        
        for(int i=0; i<n; i++)
        {
            if(intervals[i][0] > newInterval[0])
            {
                f = 0;
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }
        
        if(f)
            intervals.push_back(newInterval);
        
        mergeInterval(intervals);
        
        return intervals;
    }
};