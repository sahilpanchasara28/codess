class Solution {
public:
    int subarrayGCD(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int curr = 0;

            for (int j = i; j < n; j++) {
                curr = __gcd(curr, arr[j]);
                ans += (curr == k);
            }
        }

        return ans;
    }
};