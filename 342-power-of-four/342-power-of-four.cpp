class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        float x=log(n)/log(4);
        
        if(ceil(x)==floor(x)){
            return true;
        }
        return false;
    }
};