class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        while(!s.empty() && s.top().second <= price)
        {
            span += s.top().first;
            s.pop();
        }
        
        s.push({span, price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */