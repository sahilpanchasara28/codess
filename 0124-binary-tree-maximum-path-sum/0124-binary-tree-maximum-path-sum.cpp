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
    int ans = -1e9;
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int op1 = max(0, solve(root->left)); // left path sum
        int op2 = max(0, solve(root->right)); // right path sum
        ans = max(ans, op1+op2+root->val);
        
        return root->val + max(op1, op2);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};