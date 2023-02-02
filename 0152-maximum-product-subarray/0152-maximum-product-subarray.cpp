class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        int n = arr.size();
        int maxi = arr[0], curr1 = 1, curr2 = 1;
	    
	    for(int i=0; i<n; i++)
	    {
	        curr1 *= arr[i];
	        curr2 *= arr[n-i-1];
	        
	        maxi = max({maxi, curr1, curr2});
	        
	        if(curr1 == 0)
	            curr1 = 1;
	            
	        if(curr2 == 0)
	            curr2 = 1;
	    }
	   
	    return maxi;
    }
};