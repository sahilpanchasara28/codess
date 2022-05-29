class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size(), n2 = needle.size();
        
        for(int i=0; i<n1; i++)
        {
            if(haystack[i] == needle[0])
            {
                bool flag = true;
                for(int j=0; j<n2; j++)
                {
                    if(haystack[i+j] != needle[j])
                    {
                        flag = false;
                        break;
                    }
                }
                
                if(flag)
                    return i;
            }
        }
        
        return -1;
    }
};