class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int p) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int l = 0, h = n-1;
        int ans = 0;
        int s = 0;
        while(l <= h && (p >= arr[l] || s > 0))
        {
            while(l <= h && p >= arr[l])
            {
                p -= arr[l];
                s++;
                l++;
            }
            
            ans = max(ans, s);
            if(l <= h && s > 0)
            {
                p += arr[h];
                s--;
                h--;
            }
        }
        
        return ans;
    }
};