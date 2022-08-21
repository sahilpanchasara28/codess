class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n = blocks.size();
        int b = 0, w = 0;
        
        for(int i=0; i<k; i++)
        {
            if(blocks[i] == 'B')
                b++;
            else
                w++;
        }
        
        int ans = w;
        
        for(int i=k; i<n; i++)
        {
            //include head
            if(blocks[i] == 'B')
                b++;
            else
                w++;
            
            //exclude tail
            if(blocks[i-k] == 'B')
                b--;
            else
                w--;
            
            ans = min(ans, w);
        }
        
        return ans;
    }
};