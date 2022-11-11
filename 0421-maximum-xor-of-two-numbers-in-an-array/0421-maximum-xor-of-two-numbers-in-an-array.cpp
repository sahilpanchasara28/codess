class trieNode {
    public:
        trieNode* left; // for 0 path
        trieNode* right; // for 1 path
    
        trieNode() {
            left = NULL;
            right = NULL;
        }
};


class Solution {
public:
    trieNode* root;
    
    Solution() {
        root = new trieNode();
    }
    
    void insert(int num) {
        trieNode* curr = root;
        
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;
            
            if(bit) // is 1 
            {
                //  move right
                if(!curr->right)
                    curr->right = new trieNode();
                curr = curr->right;
            }
            else // is 0
            {
                //  move left
                if(!curr->left)
                    curr->left = new trieNode();
                curr = curr->left;
            }
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        for(auto i: nums)
            insert(i);
        
        int maxi = -1e9;
        
        for(auto e: nums)
        {
            int curr = 0;
            trieNode* node = root;
            for(int i=31; i>=0; i--)
            {
                int bit = (e >> i) & 1;
            
                if(bit) // bit is 1 so we need 0 i.e. go left
                {
                    if(node->left)
                    {
                        node = node->left;
                        curr += pow(2, i);
                    }
                    else
                        node = node->right;
                }
                else // bit is 0 so we need 1 i.e. go right
                {
                    if(node->right)
                    {
                        node = node->right;
                        curr += pow(2, i);
                    }
                    else
                        node = node->left;
                }
            }
            
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};