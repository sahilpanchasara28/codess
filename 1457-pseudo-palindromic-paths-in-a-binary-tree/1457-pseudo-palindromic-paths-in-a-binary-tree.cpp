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
    int ans = 0;
    void preorder(TreeNode* root, int cnt)
    {
        if(root == NULL)
            return;
        
        cnt ^= (1 << (root->val));
        
        if(root->left == NULL && root->right == NULL)
            ans += ((cnt & (cnt-1)) == 0);
        
        preorder(root->left, cnt);
        preorder(root->right, cnt);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
};