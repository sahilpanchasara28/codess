class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> maxheap;
        int i=0;
        
        for(i=0; i<heights.size()-1; i++)
        {
            int diff = heights[i+1] - heights[i];
            
            if(diff <= 0)
                continue;
            
            bricks -= diff;
            maxheap.push(diff);
            
            if(bricks < 0)
            {
                bricks += maxheap.top();
                maxheap.pop();
                ladders--;
            }
            
            if(ladders < 0)
                break;
        }
        return i;
    }
};