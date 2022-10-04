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
    bool hasPathSum(TreeNode* root, int t) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return (t == (root->val));
        
        bool leftCall = hasPathSum(root->left, t-(root->val));
        bool rightCall = hasPathSum(root->right, t-(root->val));
        return leftCall or rightCall;
    }
};