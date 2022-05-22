class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int zero = 0, one = 0, two = n-1;
        
        while(one <= two)
        {
            if(arr[one] == 0)
            {
                swap(arr[zero], arr[one]);
                zero++;
                one++;
            }
            else if(arr[one] == 1)
                one++;
            else
            {
                swap(arr[one], arr[two]);
                two--;
            }
        }
    }
};