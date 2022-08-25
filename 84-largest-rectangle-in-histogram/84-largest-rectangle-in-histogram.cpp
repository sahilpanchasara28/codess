class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0); //indexes store honge
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
    
     vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0); //indexes store honge
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
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> nse = nextSmallerElement(heights, n);
        vector<int> pse = prevSmallerElement(heights, n);
        
        int maxArea = -1e9;
        for(int i=0; i<n;  i++)
        {
            int h = heights[i];
            
            if(nse[i] == -1)
                nse[i] = n;
            
            int w = nse[i] - pse[i] - 1;
            
            maxArea = max(maxArea, h*w);
        }
        
        return maxArea;
    }
};