class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> l;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        int temp = s.top();
        s.pop();
        
        l.push(temp);
        
        if(l.size() > s.size())
        {
            temp = l.top();
            l.pop();
            s.push(temp);
        }
    }
    
    double findMedian() {
        if(s.size() == l.size())
            return (1.0*s.top() + 1.0*l.top())/2;
        else
            return 1.0*s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */