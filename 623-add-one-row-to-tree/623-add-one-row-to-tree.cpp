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
    
    TreeNode* solve(TreeNode* root, int d, int val, bool isLeft)
    {
        if(d == 0)
        {
            TreeNode* temp = new TreeNode(val);
            if(isLeft)
                temp->left = root;
            else
                temp->right = root;
            return temp;
        }
        
        if(root == NULL)
            return NULL;
        
        root->left = solve(root->left, d-1, val, 1);
        root->right = solve(root->right, d-1, val, 0);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root, depth-1, val, 1);
    }
};