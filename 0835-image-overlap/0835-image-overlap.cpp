class Solution {
public:
    
   unsigned int toBit(vector<int> n) {
        unsigned int bit = 0;
        
        for(auto i : n)
            bit = bit * 2 + i;
        
        return bit;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // fast solution using bit operation
        int row = A.size(), col = A[0].size();
        vector<unsigned int> bitA, bitB;
        for(int i = 0; i < row; i++) {
			// convert from vector to unsigned int
            bitA.push_back(toBit(A[i]));
            bitB.push_back(toBit(B[i]));
        }
        
        int ans = 0;
        for(int dr = -row; dr < row; dr++) for(int dc = -col; dc < col; dc++) {

            int sum = 0;
            for(int r = 0; r < row; r++) {
                if(r+dr < 0 || r+dr >= row)
                    continue;
                
                if(dc < 0)
                    sum += __builtin_popcount(bitA[r] & (bitB[r+dr] << -dc));
                else
                    sum += __builtin_popcount(bitA[r] & (bitB[r+dr] >>  dc));
            }
            ans = max(ans, sum);
        }
                
        return ans;
    }
};