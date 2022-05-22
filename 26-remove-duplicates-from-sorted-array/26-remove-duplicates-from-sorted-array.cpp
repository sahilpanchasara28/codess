class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int start = 0, end, n = arr.size();
        
        for(end = 1; end < n; end++)
            if(arr[start] != arr[end])
                arr[++start] = arr[end];
        
        return start+1;
    }
};