class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        deque<int> q;
        
        for(int i=1; i<10; i++)
            q.push_back(i);
        

        while(--n)
        {
            int size = q.size();
            
            for(int i=0; i<size; i++)
            {
                int front = q.front();
                q.pop_front();
                
                int last = front%10;
                
                if(k && last+k < 10)
                    q.push_back(front*10 + last+k);
                
                if(last-k >= 0)
                    q.push_back(front*10 + last-k);
            }
        }
        
        return vector<int>{q.begin(), q.end()};
    }
};