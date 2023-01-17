class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /*
        Intuition: move pointer wise,
            flip all left one's (including at pointer)
            and all right zero's 
        */
        
        int leftOnes = 0; // It depicts number of ones to left of pointer (including pointer) to be flipped.
        
        int rightZeros = 0; // It depicts number of zeros to right of pointer (excluding pointer) to be flipped.
                
        for(auto i: s)
        {
            // as we are starting from 0th index so rightZeros == totalZeros
            if(i == '0')
                rightZeros++;
        }
        
        // basic answer would be flipping all zeros to one
        int ans = rightZeros;
        
        for(auto i: s)
        {
            if(i == '0')
            {
                /* 
                excluding this zero, all zeros to right will be flipped
                to one, so rightZeros--;
                */
                rightZeros--;
            }
            else
            {
                /* 
                including this one, all ones to left will be flipped
                to zero, so leftOnes++;
                */
                leftOnes++;
            }
            
            // answer would be the leftOnes + rightZeros
            ans = min(ans, leftOnes + rightZeros);
        }
        
        return ans;
    }
};