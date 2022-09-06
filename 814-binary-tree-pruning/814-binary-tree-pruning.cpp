/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool One(TreeNode* &root)
    {
        if(root == NULL)
            return 0;
        
        bool left = One(root->left);
        bool right = One(root->right);
        
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        
        return root->val == 1 || left || right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        TreeNode* r1 = root;
        bool ans = One(r1);
        
        if(ans)
            return r1;
        else
            return NULL;
    }
};