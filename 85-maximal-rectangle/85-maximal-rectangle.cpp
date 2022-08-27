class Solution {
public:
    
    vector<int> nse(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--)
        {
            while(s.top() != -1 && arr[s.top()] >= arr[i])
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    vector<int> pse(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0);
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++)
        {
            while(s.top() != -1 && arr[s.top()] >= arr[i])
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    int maxAreaHistogram(vector<int> &arr, int n)
    {
        vector<int> next = nse(arr, n);
        vector<int> prev = pse(arr, n);
        int maxi = -1e9;
        
        for(int i=0; i<n; i++)
        {
            int h = arr[i];
            
            if(next[i] == -1)
                next[i] = n;
            
            int w = next[i]-prev[i]-1;
            
            maxi = max(maxi, h*w);
        }
        
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> curr(m, 0);
        
        int maxi = -1e9;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == '1')
                    curr[j]++;
                else
                    curr[j]=0;
            }
            
            int currAns = maxAreaHistogram(curr, m);
            maxi = max(maxi, currAns);
        }
        
        return maxi;
    }
};