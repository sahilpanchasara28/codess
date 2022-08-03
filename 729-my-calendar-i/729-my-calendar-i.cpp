class MyCalendar {
public:
    
    vector<pair<int, int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto c: cal)
        {
            if(start < c.second && c.first < end)
                return false;
        }
        
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */