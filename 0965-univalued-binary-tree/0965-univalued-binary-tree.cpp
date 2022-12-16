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
    
    bool solve(TreeNode* root, int val)
    {
        if(root == NULL)
            return true;
        
        if(root->val == val)
            return solve(root->left, val) and solve(root->right, val);
        return false;
    }
    
    bool isUnivalTree(TreeNode* root) {
        return solve(root, root->val);
    }
};