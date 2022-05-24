class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                int lo = j+1, hi = n-1, targ = t-arr[i]-arr[j];
                while(lo < hi)
                {
                    int sum = arr[lo] + arr[hi];
                    if(sum == targ)
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[lo]);
                        temp.push_back(arr[hi]);
                        ans.push_back(temp);
                        
                        // skipping duplicates of third number
                        while(lo < hi && arr[lo] == arr[lo+1])
                            lo++;
                        
                        // skipping duplicates of fourth number
                        while(lo < hi && arr[hi] == arr[hi-1])
                            hi--;
                        
                        lo++;
                        hi--;
                    }
                    else if(sum < targ)
                        lo++;
                    else
                        hi--;
                }
                
                // skipping duplicates of second number
                while (j + 1 < n && arr[j] == arr[j+1])
                    j++;
            }
            // skipping duplicates of second number
            while (i + 1 < n && arr[i] == arr[i+1])
                i++;
        }
        return ans;
    }
};