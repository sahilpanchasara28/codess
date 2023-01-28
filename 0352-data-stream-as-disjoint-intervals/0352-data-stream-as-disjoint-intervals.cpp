class SummaryRanges {
public:
    set<int> s;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        
        int left = -1, right = -1;
        
        for(auto i: s)
        {
            if(left < 0)
                left = right = i;
            else if(i == right+1)
                right = i;
            else {
                ans.push_back({left, right});
                left = right = i;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */