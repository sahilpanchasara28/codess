class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int n = arr.size(), curr = 0, ans;
        for(int i=0; i<k; i++)
            curr += arr[i];
        
        if(k == n)
            return curr;
        
        ans = curr;
        int left = k-1, right = n-1;
        while(left >= 0)
        {
            curr += (arr[right] - arr[left]);
            ans = max(ans, curr);
            right--;
            left--;
        }
        
        return ans;
    }
};