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
    bool evaluateTree(TreeNode* root) {
        
        if(root->left == NULL and root->right == NULL)
            return root->val;
        
        switch(root->val) {
            case 2: root->val = evaluateTree(root->left) or evaluateTree(root->right);
                break;
                
            case 3: root->val = evaluateTree(root->left) and evaluateTree(root->right);
                break;
        }
        
        return root->val;
    }
};