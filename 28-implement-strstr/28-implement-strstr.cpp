class Solution {
public:
    int strStr(string haystack, string needle) {

        int large = haystack.size (), small = needle.size ();
    
    for (int i = 0; i <= large - small; i++)
      {
	int j;
	for (j = 0; j < small; j++)
	  {
	    if (haystack[i + j] != needle[j])
	      {
		break;
	      }
	  }
	if (j == small)
	  {
	    return i;
	  }
      }
    return -1;
  
        
    }
};